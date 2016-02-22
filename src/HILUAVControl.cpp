//============================================================================
// Name        : HILUAVControl.cpp
// Author      : Fernando Silvano Gonçalves
// Version     :
// Copyright   : @2014 Federal University of Santa Catarina
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "translationalControl.h"
#include "signalTransformation.h"
#include "rotacionalControl.h"
#include "globalVariables.h"
#include "angularVelocity.h"
#include "socketTCPIP.h"
#include "references.h"
#include "position.h"
#include "velocity.h"
#include "atitude.h"
#include "errors.h"
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

#define NSEC_PER_SEC    (1000000000) /* The number of nsecs per sec. */
#define PERIOD     5000000

pthread_mutex_t communicationMutex = PTHREAD_MUTEX_INITIALIZER;

//------ Global classes used from both communication and control threads
signalTransformation sigTrans;
angularVelocity angVel;
position pos;
velocity vel;
atitude atd;

//------ Function Prototypes --------------
void *controlThread(void *ptr);
void *communicationThread(void *ptr);

int main() {
	int rc;

	cout << "UAV" << endl; // prints UAV

	pthread_t threadCommunication;
	pthread_t threadControl;

	//Thread creation
	printf("Creation of the threads \n");
	rc = pthread_create(&threadControl, NULL, controlThread, (void *) 0);
	if (rc) {
		printf("ERROR; pthread_create() Control rc is %d\n", rc);
		perror(NULL);
		exit(-1);
	}

	rc = pthread_create(&threadCommunication, NULL, communicationThread, (void *) 0);
	if (rc) {
		printf("ERROR; pthread_create() IMU rc is %d\n", rc);
		perror(NULL);
		exit(-1);
	}

	printf("Start running\n");

	pthread_join(threadCommunication, NULL);
	pthread_join(threadControl, NULL);

	return 0;
}

void *controlThread(void *ptr) {
	struct timespec t;

	translationalControl trans;
	rotacionalControl rot;
	references ref;
	errors error;

	sigTrans.setFL(0);
	sigTrans.setFR(0);
	sigTrans.setAlphaL(0);
	sigTrans.setAlphaR(0);

	ref.setRefX(0.1);
	ref.setRefY(0.1);
	ref.setRefZ(0.1);
	ref.setRefDotX(0);
	ref.setRefDotY(0);
	ref.setRefDotZ(0);
	ref.setDotPhiRef(0);
	ref.setDotThetaRef(0);
	ref.setDotPsiRef(0);

	clock_gettime(CLOCK_MONOTONIC, &t);
	/* start after one second */
	t.tv_sec++;
	while (created) {
		/* wait until next shot */
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t, NULL);
		if (running) {
			pthread_mutex_lock(&communicationMutex);
			//	//////	Generate Errors
			error.generateErrors(ref, pos, vel);

			trans.transControl(error, atd, rot.getTauTheta());

			//// ROTATIONAL CONTROL
			trans.setPsiRef(-0.1);

			rot.rotationalController(atd, angVel, ref, trans);

			// SIGNAL TRANSFORMATION
			sigTrans.sigTrans(trans, rot);

			pthread_mutex_unlock(&communicationMutex);
			//	fprintf(BEAGLEfp, "\nTime:	%.10f	Deadlines fault:	%d",
			//			((stop - start) * 1000), x);
			//
			////		fprintf(BEAGLEfp, "\n%.10f	%.10f	%.10f	%.10f", sigTransG.getR(),
			////					sigTransG.getL(), sigTransG.getAlphaR(),
			////					sigTransG.getAlphaL());
			////		}
			//}
		}
		/* calculate next shot */
		t.tv_nsec += PERIOD;

		while (t.tv_nsec >= NSEC_PER_SEC) {
			t.tv_nsec -= NSEC_PER_SEC;
			t.tv_sec++;
		}
	}
}

void *communicationThread(void *ptr) {
	struct timespec t;

	BeaglePackage beagle;
	PcPackage pc;

	//initialize structs
	beagle.fL = 0;
	beagle.fR = 0;
	beagle.alphaL = 0;
	beagle.alphaR = 0;

	pc.x = 0;
	pc.y = 0;
	pc.z = 0;
	pc.phi = 0;
	pc.theta = 0;
	pc.psi = 0;
	pc.dotPhi = 0;
	pc.dotTheta = 0;
	pc.dotPsi = 0;
	pc.dotX = 0;
	pc.dotY = 0;
	pc.dotZ = 0;

	//Create TCP/IP Objects to connect with Matlab Simulink
	socketTCPIP comm1(8081, "192.168.0.5");

	socketTCPIP comm2(8082, "192.168.0.5");

	comm1.connect();
	comm2.connect();

	running = 1;

	cout << "Connections ok!" << endl;

	clock_gettime(CLOCK_MONOTONIC, &t);
	/* start after one second */
	t.tv_sec++;
	while (created) {
		/* wait until next shot */
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t, NULL);
		if (running) {
			pthread_mutex_lock(&communicationMutex);

//			Seta vairáveis para envio
			beagle.fR = sigTrans.getFR();
			beagle.fL = sigTrans.getFL();
			beagle.alphaR = sigTrans.getAlphaR();
			beagle.alphaL = sigTrans.getAlphaL();

			pthread_mutex_unlock(&communicationMutex);

			comm1.sendData(beagle);

			pc = comm2.receiveData();

			if (pc.flag > -1) {
				pthread_mutex_lock(&communicationMutex);

				//Update position
				pos.setX(pc.x);
				pos.setY(pc.y);
				pos.setZ(pc.z);
				//Update velocity
				vel.setDotX(pc.dotX);
				vel.setDotY(pc.dotY);
				vel.setDotZ(pc.dotZ);
				//Update atitude
				atd.setPhi(pc.phi);
				atd.setTheta(pc.theta);
				atd.setPsi(pc.psi);
				//Update angular velocity
				angVel.setDotPhi(pc.dotPhi);
				angVel.setDotTheta(pc.dotTheta);
				angVel.setDotPsi(pc.dotPsi);

				pthread_mutex_unlock(&communicationMutex);

			}
			/* calculate next shot */
			t.tv_nsec += PERIOD;

			while (t.tv_nsec >= NSEC_PER_SEC) {
				t.tv_nsec -= NSEC_PER_SEC;
				t.tv_sec++;
			}

		}
	}
}
