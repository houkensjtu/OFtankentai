// time
#include "fvCFD.H"

int main(int argc, char *argv[])
{
	argList args(argc, argv);

	if(!args.checkRootCase()){
		FatalError.exit();
	}

	Time runTime(Time::controlDictName,
		args.rootPath(), args.caseName());

	Info << "controlDict name: " << runTime.controlDictName << endl;
	Info << "root path: " << runTime.rootPath() << endl;
	Info << "case name: " << runTime.caseName() << endl;
	Info << "path: " << runTime.path() << endl;
	Info << "time path: " << runTime.timePath() << endl;
	Info << "format: " << runTime.writeFormat() << endl;
	Info << "version: " << runTime.writeVersion() << endl;
	Info << "compression: " << runTime.writeCompression() << endl;

	Info << "start time: " << runTime.startTime() << endl;
	Info << "end time: " << runTime.endTime() << endl;
	Info << "deltaT: " << runTime.deltaT() << endl;

	runTime.writeNow();

	while(runTime.loop()){
		Info << "Time: " << runTime.timeName() << endl;
		runTime.write();
	}

	runTime.writeAndEnd();

	Info << "execution time: " << runTime.elapsedCpuTime() << " s" << endl;
	Info << "clock time: " << runTime.elapsedClockTime() << " s" << endl;

	return 0;
}
