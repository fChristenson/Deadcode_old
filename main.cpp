#include <iostream>
#include <set>
#include "libs/PathUtils.hpp"
#include "libs/FileUtils.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
  vector<FileData> files = walkDirectory(argv[1], fileToFileData);
  set<string> possibleDeadFiles = findDeadFiles(files);

  cout << "===========================================" << endl;
  cout << "      The following files may be dead      " << endl;
  cout << "===========================================" << endl;

  for (set<string>::iterator i = possibleDeadFiles.begin(); i != possibleDeadFiles.end(); i++)
  {
    cout << *i << endl;
  }

  return 0;
}
