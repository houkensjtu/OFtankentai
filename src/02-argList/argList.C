// argList
#include "fvCFD.H"

int main(int argc, char *argv[])
{
	argList args(argc, argv);

	if(!args.checkRootCase()){
		FatalError.exit();
	}

	Info << "root path: " << args.rootPath() << endl;
	Info << "case name: " << args.caseName() << endl;
	Info << "path: " << args.path() << endl;

	return 0;
}
