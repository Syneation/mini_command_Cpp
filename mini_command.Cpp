#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <filesystem>
#include <string>

using namespace std;

namespace fs = filesystem;

void openFolder();
void deleteFolder();
void readFile();
void deleteFile();

int main()
{
    //UTF-8
    SetConsoleOutputCP(CP_UTF8);

    int choice;
    cout << "Enter choice" << endl;
    cout << "0 - exit" << endl;
    cout << "1 - open folder" << endl;
    cout << "2 - delete folder" << endl;
    cout << "3 - read file" << endl;
    cout << "4 - delete file" << endl;
    cout << "command>>";
    cin >> choice;
    switch (choice)
    {
        case 0:
            cout << "Bye";
            break;

        case 1:
            openFolder();
            break;
        
        case 2:
            deleteFolder();
            break;
        
        case 3:
            readFile();
            break;

        case 4:
            deleteFile();
            break;
    

        default:
            cout << "Error 404";
            break;
    }
}

//open folder
void openFolder()
{
    //UTF-8
    SetConsoleOutputCP(CP_UTF8);

    char fullPathForExplorer[100];
    char isOpenExlporer;

    string path;
    int countFile = 0;

    cout << "Enter path>> ";

    cin >> path;

    //get path for explorer
    char * path_explr = path.data();

    sprintf(fullPathForExplorer, "Explorer %s", path_explr);

    try 
    {
        for (const auto & entry : fs::directory_iterator(path)) 
        {
        countFile++;
        cout << "File " << countFile <<  entry.path() << ":" << endl;
        }
    } catch (...)
    {
        cout << "ERROR: 404" << endl;
        main();
    }
    cout << "Open in explorer? (Y / N) >>";
    cin >> isOpenExlporer;
    if (isOpenExlporer == 'Y' || isOpenExlporer == 'y')      
    {
        system(fullPathForExplorer);
        main();
    }
    else main();
}

//delete folder
void deleteFolder()
{
    //UTF-8
    SetConsoleOutputCP(CP_UTF8);

    string path;

    error_code errorCode;

    cout << "Enter path>> ";
    cin >> path;

    if (!fs::remove_all(path, errorCode))
    {
        cout << "Error: " << errorCode.message() << endl;
        main();
    } else fs::remove_all(path);

    cout << "Folder has been successfully deleted." << endl;
    main();
 
}

//open file
void readFile()
{
    //UTF-8
    SetConsoleOutputCP(CP_UTF8);

    string Text;
    string path;

    cout << "Enter path>> ";
    cin >> path;

    ifstream ReadFile(path);

    while (getline (ReadFile, Text))
    {
        cout << Text;
    }
    cout << endl;

    if (Text.length() == 0)
        cout << "Error 404 OR Empty file" << endl;

    ReadFile.close();
    main();
}

//delete file
void deleteFile()
{
    //UTF-8
    SetConsoleOutputCP(CP_UTF8);

    string Text;
    string path;

    cout << "Enter path>> ";
    cin >> path;

    //get path for delete
    char * path_d = path.data();

    if (!remove(path_d))
    {
        cout << "File has been successfully deleted." << endl;
        main();
    }
    else 
    {
        cout << "Error: 404" << endl;
        main();
    }
    
}