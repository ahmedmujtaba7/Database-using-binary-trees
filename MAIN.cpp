#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<sstream>

#include"Red_Black_Tree.h"
#include"AVL.h"

using namespace std;

void Generating_AVLTree(int choice);
void Generating_RBTree(int choice);

class DeathCauses
{
public:
    int ID;
    int Year;
    string CauseName113, CauseName;
    string State;
    int Deaths;
    float Age;
};

void ReadTuple(string line, DeathCauses* record)   // file reading
{
    string cause_name;
    string cause;
    string state;
    int death;
    float death_rate;//variables for each column
    string temp = "";//a string to store values other than string 
    stringstream inputstring(line);//a stringstream object of lib <sstream> that convert line that is read into string
    stringstream inputstring2(line);
    getline(inputstring, temp, ',');//saving inputstring into temp until ',' is encountered
    getline(inputstring2, temp, ',');//saving inputstring into temp until ',' is encountered
    record->ID = atoi(temp.c_str());//atoi(temp.c_str()) changes string into int
    temp = "";//making temp empty so it could be used for other variables
    getline(inputstring, temp, ',');
    getline(inputstring2, temp, ',');//saving inputstring into temp until ',' is encountered
    record->Year = atoi(temp.c_str());//string to int
    char ch;
    int count = 0;
    string waster;
    while (inputstring.get(ch)) {//read a character
        if (ch == '"') {
            getline(inputstring, record->CauseName113, '"');//saving cause of death into the variable cause_name
            getline(inputstring, waster, ',');
            count = 1;
            break;
        }
        else {
            count = 0;
            getline(inputstring2, record->CauseName113, ',');//saving cause of death into the variable cause_name
            
            break;
        }
    }
    if (count == 1) {
        getline(inputstring, record->CauseName, ',');//saving cause into cause variable
       // getline(inputstring, record->CauseName113, ',');//saving cause of death into the variable cause_name

     //   getline(inputstring, record->CauseName, ',');//saving cause into cause variable

        getline(inputstring, record->State, ',');//saving state in state variable

        temp = "";//making temp empty for further use

        getline(inputstring, temp, ',');
        record->Deaths = atoi(temp.c_str());//string to int

        temp = "";//making temp empty for further use

        getline(inputstring, temp, ',');
        record->Age = atof(temp.c_str());//string to float

        //deathrecord deaths(Id, Year, cause_name, cause, state, death, death_rate);//read next comment
        ////making a class deathrecord varaible and pasing parameters to initialize in constructor
        //deatho.push_back(deaths);//a vector library function to push values into the vector variable 
        ////at the end and increases the vector size by 1

        temp = "";//making temp empty for next iteration
    }
    else {
        getline(inputstring2, record->CauseName, ',');//saving cause into cause variable
      // getline(inputstring, record->CauseName113, ',');//saving cause of death into the variable cause_name

    //   getline(inputstring, record->CauseName, ',');//saving cause into cause variable

        getline(inputstring2, record->State, ',');//saving state in state variable

        temp = "";//making temp empty for further use

        getline(inputstring2, temp, ',');
        record->Deaths = atoi(temp.c_str());//string to int

        temp = "";//making temp empty for further use

        getline(inputstring2, temp, ',');
        record->Age = atof(temp.c_str());//string to float

        //deathrecord deaths(Id, Year, cause_name, cause, state, death, death_rate);//read next comment
        ////making a class deathrecord varaible and pasing parameters to initialize in constructor
        //deatho.push_back(deaths);//a vector library function to push values into the vector variable 
        ////at the end and increases the vector size by 1

        temp = "";//making temp empty for next iteration
    }

}

template<class T>
void DisplayRecords(AVLNode<T>* FoundNode)  // searched node address passed
{
    DeathCauses record;    //obj
    fstream input;  // filename
    int LineNo;
    string line;
    AVLNode<T>* CurrNode = FoundNode;


    // system("cls");
    cout << endl << endl << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "ID" << "   " << setw(10) << "Year" << "   " << setw(25) << "Cause Name" << "   " << setw(25) << "State" << "   " << setw(10) << "Deaths" << "    " << setw(10) << "Age" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (CurrNode != NULL)   // searched node not null
    {
        input.open(CurrNode->path, ios::in);  // read mode
        LineNo = 0;
        if (!input)
            cout << "Can't open file";
        else
        {
            getline(input, line);// file and line
            LineNo++;
            while (getline(input, line))
            {
                LineNo++;
                if (LineNo == CurrNode->LineNo)
                {
                    ReadTuple(line, &record);
                    cout << setw(10) << record.ID << "   " << setw(10) << record.Year << "   " << setw(25) << record.CauseName << "   " << setw(25) << record.State << "   " << setw(10) << record.Deaths << "    " << setw(10) << record.Age << endl;
                    cout << "\n\t113 Cause Name : " << record.CauseName113 << "   \n\n";
                }
            }
        }
        CurrNode = CurrNode->next;   /// reads linked list
        input.close();  // file closed
    }
}

template<class T>
void RBDisplayRecords(Node<T>* FoundNode)  // searched node address passed
{
    DeathCauses record;    //obj
    fstream input;  // filename
    int LineNo;
    string line;
    Node<T>* CurrNode = FoundNode;

    //system("cls");
    cout << endl << endl << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "ID" << "   " << setw(10) << "Year" << "   " << setw(25) << "Cause Name" << "   " << setw(25) << "State" << "   " << setw(10) << "Deaths" << "    " << setw(10) << "Age" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    while (CurrNode != NULL)   // searched node not null
    {
        input.open(CurrNode->path, ios::in);  // read mode
        LineNo = 0;
        if (!input)
            cout << "Can't open file";
        else
        {
            getline(input, line);// file and line
            LineNo++;
            while (getline(input, line))
            {
                LineNo++;
                if (LineNo == CurrNode->LineNo)
                {
                    ReadTuple(line, &record);
                    cout << setw(10) << record.ID << "   " << setw(10) << record.Year << "   " << setw(25) << record.CauseName << "   " << setw(25) << record.State << "   " << setw(10) << record.Deaths << "    " << setw(10) << record.Age << endl;
                }
            }
        }
        CurrNode = CurrNode->next;   /// reads linked list
        input.close();  // file closed
    }
}

void CreateDirectory(int choice)
{
    if (choice == 1)
        system("mkdir D:\\Indexed\\AVLID");
    else if (choice == 2)
        system("mkdir D:\\Indexed\\AVLYear");
    else if (choice == 3)
        system("mkdir D:\\Indexed\\AVLCause");
    else if (choice == 4)
        system("mkdir D:\\Indexed\\AVLState");
    else if (choice == 5)
        system("mkdir D:\\Indexed\\AVLDeaths");
    else if (choice == 6)
        system("mkdir D:\\Indexed\\AVLAge");
}

void RBCreateDirectory(int choice)
{
    if (choice == 1)
        system("mkdir D:\\Indexed\\RBID");
    else if (choice == 2)
        system("mkdir D:\\Indexed\\RBYear");
    else if (choice == 3)
        system("mkdir D:\\Indexed\\RBCause");
    else if (choice == 4)
        system("mkdir D:\\Indexed\\RBState");
    else if (choice == 5)
        system("mkdir D:\\Indexed\\RBDeaths");
    else if (choice == 6)
        system("mkdir D:\\Indexed\\RBAge");
}
template <class T>
void RBDeleteRecords(Node<T>* FoundNode, int choice)  // Whatever Node user has put in to be deleted
{
    DeathCauses record;  // obj
    fstream input, output;  // 2 files...input for reading and output is copy file
    string line;

    Node<T>* CurrNode = FoundNode;  // currnode will traverse

    while (CurrNode != NULL)
    {
        input.open(CurrNode->path, ios::in);  // read mode
        output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out); // write mode

        if (!input)
            cout << "Can't open file";
        if (!output)
            cout << "Can't open output file";

        getline(input, line);
        output << line;    // for heading

        while (getline(input, line))  // reads till eof
        {
            ReadTuple(line, &record);
            if (CurrNode->ID != record.ID)     // skip line to delete from the database
                output << line << endl;
        }

        input.close();
        output.close();

        remove(CurrNode->path.c_str());  // will delete file it reads from(orignal file)
        rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", CurrNode->path.c_str());// output file renamed(temporary)

        CurrNode = CurrNode->next; // for similar cases, all values deleted
    }
}

template <class T>
void DeleteRecords(AVLNode<T>* FoundNode, int choice)  // Whatever Node user has put in to be deleted
{
    DeathCauses record;  // obj
    fstream input, output;  // 2 files...input for reading and output is copy file
    string line;

    AVLNode<T>* CurrNode = FoundNode;  // currnode will traverse

    while (CurrNode != NULL)
    {
        input.open(CurrNode->path, ios::in);  // read mode
        output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out); // write mode

        if (!input)
            cout << "Can't open file";
        if (!output)
            cout << "Can't open output file";

        getline(input, line);
        output << line;    // for heading

        while (getline(input, line))  // reads till eof
        {
            ReadTuple(line, &record);
            if (CurrNode->ID != record.ID)     // skip line to delete from the database
                output << line << endl;
        }

        input.close();
        output.close();

        remove(CurrNode->path.c_str());  // will delete file it reads from(orignal file)
        rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", CurrNode->path.c_str());// output file renamed(temporary)

        CurrNode = CurrNode->next; // for similar cases, all values deleted
    }
}
void RBUpdateRecords(Node<int>* intFoundNode, Node<float>* floatFoundNode, Node<string>* stringFoundNode, int choice, string FieldName, int Iprev_val, int Inew_val, string Sprev_val, string Snew_val, float Fprev_val, float Fnew_val) {

    DeathCauses record;
    fstream input, output;
    string line;


    Node<int>* Curr_NodeInt;
    Node<float>* Curr_NodeFloat;
    Node<string>* Curr_NodeString;


    if (choice == 1 || choice == 2 || choice == 5)
    {
        Curr_NodeInt = intFoundNode;

        while (Curr_NodeInt != NULL)
        {
            input.open(Curr_NodeInt->path, ios::in);
            output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out);

            if (!input)
                cout << "Can't open file";
            if (!output)
                cout << "Can't open output file";

            getline(input, line);
            output << line << endl;  // for heading

            while (getline(input, line))
            {
                ReadTuple(line, &record);
                if (Curr_NodeInt->ID == record.ID)   // Update record in file
                {

                    if (FieldName == "Year")
                    {
                        if (record.Year == Iprev_val)  //if year matches replace with the new value
                            output << record.ID << "," << Inew_val << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "CauseName")
                    {
                        if (record.CauseName == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << Snew_val << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "State")
                    {
                        if (record.State == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << Snew_val << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Deaths")
                    {
                        if (record.Deaths == Iprev_val)  //if No of Deaths matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << Inew_val << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Age")
                    {
                        if (record.Age == Fprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << Fnew_val << endl;
                        else
                            output << line << endl;
                    }

                }
                else
                    output << line << endl;
            }
            input.close();
            output.close();

            remove(Curr_NodeInt->path.c_str());
            rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", Curr_NodeInt->path.c_str());

            Curr_NodeInt = Curr_NodeInt->next;
        }
    }
    else if (choice == 3 || choice == 4)
    {
        Curr_NodeString = stringFoundNode;


        while (Curr_NodeString != NULL)
        {
            input.open(Curr_NodeString->path, ios::in);
            output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out);

            if (!input)
                cout << "Can't open file";
            if (!output)
                cout << "Can't open output file";

            getline(input, line);
            output << line << endl;  // for heading

            while (getline(input, line))
            {
                ReadTuple(line, &record);
                if (Curr_NodeString->ID == record.ID)   // Update record in file
                {

                    if (FieldName == "Year")
                    {
                        if (record.Year == Iprev_val)  //if year matches replace with the new value
                            output << record.ID << "," << Inew_val << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "CauseName")
                    {
                        if (record.CauseName == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << Snew_val << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "State")
                    {
                        if (record.State == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << Snew_val << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Deaths")
                    {
                        if (record.Deaths == Iprev_val)  //if No of Deaths matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << Inew_val << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Age")
                    {
                        if (record.Age == Fprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << Fnew_val << endl;
                        else
                            output << line << endl;
                    }

                }
                else
                    output << line << endl;
            }
            input.close();
            output.close();

            remove(Curr_NodeString->path.c_str());
            rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", Curr_NodeString->path.c_str());

            Curr_NodeString = Curr_NodeString->next;
        }
    }
    else
    {
        Curr_NodeFloat = floatFoundNode;

        while (Curr_NodeFloat != NULL)
        {
            input.open(Curr_NodeFloat->path, ios::in);
            output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out);

            if (!input)
                cout << "Can't open file";
            if (!output)
                cout << "Can't open output file";

            getline(input, line);
            output << line << endl;  // for heading

            while (getline(input, line))
            {
                ReadTuple(line, &record);
                if (Curr_NodeFloat->ID == record.ID)   // Update record in file
                {

                    if (FieldName == "Year")
                    {
                        if (record.Year == Iprev_val)  //if year matches replace with the new value
                            output << record.ID << "," << Inew_val << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "CauseName")
                    {
                        if (record.CauseName == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << Snew_val << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "State")
                    {
                        if (record.State == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << Snew_val << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Deaths")
                    {
                        if (record.Deaths == Iprev_val)  //if No of Deaths matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << Inew_val << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Age")
                    {
                        if (record.Age == Fprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << Fnew_val << endl;
                        else
                            output << line << endl;
                    }

                }
                else
                    output << line << endl;
            }
            input.close();
            output.close();

            remove(Curr_NodeFloat->path.c_str());
            rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", Curr_NodeFloat->path.c_str());

            Curr_NodeFloat = Curr_NodeFloat->next;
        }

    }
}


void UpdateRecords(AVLNode<int>* intFoundNode, AVLNode<float>* floatFoundNode, AVLNode<string>* stringFoundNode, int choice, string FieldName, int Iprev_val, int Inew_val, string Sprev_val, string Snew_val, float Fprev_val, float Fnew_val)
{
    DeathCauses record;
    fstream input, output;
    string line;


    AVLNode<int>* Curr_NodeInt;
    AVLNode<float>* Curr_NodeFloat;
    AVLNode<string>* Curr_NodeString;


    if (choice == 1 || choice == 2 || choice == 5)
    {
        Curr_NodeInt = intFoundNode;

        while (Curr_NodeInt != NULL)
        {
            input.open(Curr_NodeInt->path, ios::in);
            output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out);

            if (!input)
                cout << "Can't open file";
            if (!output)
                cout << "Can't open output file";

            getline(input, line);
            output << line << endl;  // for heading

            while (getline(input, line))
            {
                ReadTuple(line, &record);
                if (Curr_NodeInt->ID == record.ID)   // Update record in file
                {

                    if (FieldName == "Year")
                    {
                        if (record.Year == Iprev_val)  //if year matches replace with the new value
                            output << record.ID << "," << Inew_val << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "CauseName")
                    {
                        if (record.CauseName == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << Snew_val << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "State")
                    {
                        if (record.State == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << Snew_val << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Deaths")
                    {
                        if (record.Deaths == Iprev_val)  //if No of Deaths matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << Inew_val << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Age")
                    {
                        if (record.Age == Fprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << Fnew_val << endl;
                        else
                            output << line << endl;
                    }

                }
                else
                    output << line << endl;
            }
            input.close();
            output.close();

            remove(Curr_NodeInt->path.c_str());
            rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", Curr_NodeInt->path.c_str());

            Curr_NodeInt = Curr_NodeInt->next;
        }
    }
    else if (choice == 3 || choice == 4)
    {
        Curr_NodeString = stringFoundNode;


        while (Curr_NodeString != NULL)
        {
            input.open(Curr_NodeString->path, ios::in);
            output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out);

            if (!input)
                cout << "Can't open file";
            if (!output)
                cout << "Can't open output file";

            getline(input, line);
            output << line << endl;  // for heading

            while (getline(input, line))
            {
                ReadTuple(line, &record);
                if (Curr_NodeString->ID == record.ID)   // Update record in file
                {

                    if (FieldName == "Year")
                    {
                        if (record.Year == Iprev_val)  //if year matches replace with the new value
                            output << record.ID << "," << Inew_val << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "CauseName")
                    {
                        if (record.CauseName == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << Snew_val << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "State")
                    {
                        if (record.State == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << Snew_val << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Deaths")
                    {
                        if (record.Deaths == Iprev_val)  //if No of Deaths matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << Inew_val << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Age")
                    {
                        if (record.Age == Fprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << Fnew_val << endl;
                        else
                            output << line << endl;
                    }

                }
                else
                    output << line << endl;
            }
            input.close();
            output.close();

            remove(Curr_NodeString->path.c_str());
            rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", Curr_NodeString->path.c_str());

            Curr_NodeString = Curr_NodeString->next;
        }
    }
    else
    {
        Curr_NodeFloat = floatFoundNode;

        while (Curr_NodeFloat != NULL)
        {
            input.open(Curr_NodeFloat->path, ios::in);
            output.open("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", ios::out);

            if (!input)
                cout << "Can't open file";
            if (!output)
                cout << "Can't open output file";

            getline(input, line);
            output << line << endl;  // for heading

            while (getline(input, line))
            {
                ReadTuple(line, &record);
                if (Curr_NodeFloat->ID == record.ID)   // Update record in file
                {

                    if (FieldName == "Year")
                    {
                        if (record.Year == Iprev_val)  //if year matches replace with the new value
                            output << record.ID << "," << Inew_val << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "CauseName")
                    {
                        if (record.CauseName == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << Snew_val << "," << record.State << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "State")
                    {
                        if (record.State == Sprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << Snew_val << "," << record.Deaths << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Deaths")
                    {
                        if (record.Deaths == Iprev_val)  //if No of Deaths matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << Inew_val << "," << record.Age << endl;
                        else
                            output << line << endl;
                    }
                    else if (FieldName == "Age")
                    {
                        if (record.Age == Fprev_val)  //if cause name matches replace with the new value
                            output << record.ID << "," << record.Year << "," << record.CauseName113 << "," << record.CauseName << "," << record.State << "," << record.Deaths << "," << Fnew_val << endl;
                        else
                            output << line << endl;
                    }

                }
                else
                    output << line << endl;
            }
            input.close();
            output.close();

            remove(Curr_NodeFloat->path.c_str());
            rename("C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\temp.csv", Curr_NodeFloat->path.c_str());

            Curr_NodeFloat = Curr_NodeFloat->next;
        }

    }
}

// function overloading
void Searching_RBTree(int choice, Node<float>* Root_float, Node<string>* Root_string, Node<int>* Root_int, char Rch)  // indexing choice, root of all types
{
    bool found = false;

    Node<int>* intFoundNode = NULL;
    Node<string>* stringFoundNode = NULL;
    Node<float>* floatFoundNode = NULL;

    int id1, id2; // between these ranges
    int year1, year2;
    int death1, death2;
    float age1, age2;

    if (choice == 1)
    {
        cout << endl << endl << endl << "Enter Range for IDs to be searched:  ";
        cout << "Range1: ";
        cin >> id1;
        cout << "Range2: ";
        cin >> id2;

        for (int i = id1; i <= id2; i++)  // loop from id1 to id2
        {
            intFoundNode = search(Root_int, i, found);

            if (intFoundNode != NULL)
                RBDisplayRecords(intFoundNode);
        }
    }

    else if (choice == 2)
    {
        cout << endl << endl << endl << "Enter Range for Years to be searched:  ";
        cout << "Range1: ";
        cin >> year1;
        cout << "Range2: ";
        cin >> year2;
        for (int i = year1; i <= year2; i++)  // will search btw these years
        {
            intFoundNode = search(Root_int, i, found);

            if (intFoundNode != NULL)
                RBDisplayRecords(intFoundNode);
        }
    }



    else if (choice == 5)
    {
        cout << endl << endl << endl << "Enter Range for Ages to be searched:  ";
        cout << "Range1: ";
        cin >> death1;
        cout << "Range2: ";
        cin >> death2;
        for (int i = death1; i <= death2; i++)  // will search btw these ages
        {
            intFoundNode =
                search(Root_int, i, found);

            if (intFoundNode != NULL)
                RBDisplayRecords(intFoundNode);
        }
    }

    else if (choice == 6)
    {
        cout << endl << endl << endl << "Enter Range for Ages to be searched:  ";
        cout << "Range1: ";
        cin >> age1;
        cout << "Range2: ";
        cin >> age2;

        for (float i = age1; i <= age2; i++)  // will search btw these ages
        {
            floatFoundNode = search(Root_float, i, found);

            if (floatFoundNode != NULL)
                RBDisplayRecords(floatFoundNode);
        }
    }
}

void Searching_RBTree(int choice, Node<float>* Root_float, Node<string>* Root_string, Node<int>* Root_int) {
    string stateName, cause;
    int ID, Year, Deaths;
    float Age;
    bool found = false;
    int operation_choice;

    Node<int>* intFoundNode = NULL;
    Node<string>* stringFoundNode = NULL;
    Node<float>* floatFoundNode = NULL;

    int Field_Choice = 0;
    string FieldName = "";

    int Iprev_val = 0, Inew_val = 0;
    string Sprev_val = "", Snew_val = "";
    float Fprev_val = 0, Fnew_val = 0;

    if (choice == 1)  // ID
    {
        cout << endl << endl << endl << "Enter ID to be searched:  ";
        cin >> ID;

        intFoundNode = search(Root_int, ID, found);  // new node address returned (that was being searched)

        if (intFoundNode != NULL)
            RBDisplayRecords(intFoundNode);
    }
    else if (choice == 2)
    {
        cout << endl << endl << endl << "Enter Year to be searched:  ";
        cin >> Year;

        intFoundNode = search(Root_int, Year, found);

        if (intFoundNode != NULL)
            RBDisplayRecords(intFoundNode);

    }
    else if (choice == 3)
    {
        getchar();

        cout << endl << endl << endl << "Enter Cause to be searched:  ";
        getline(cin, cause);
        stringFoundNode = search(Root_string, cause, found);

        if (stringFoundNode != NULL)
            RBDisplayRecords(stringFoundNode);

    }
    else if (choice == 4)
    {
        getchar();

        cout << endl << endl << endl << "Enter name of state to be searched:  ";
        getline(cin, stateName);

        cout << endl << endl;
        stringFoundNode = search(Root_string, stateName, found);

        if (stringFoundNode != NULL)
            RBDisplayRecords(stringFoundNode);

    }
    else if (choice == 5)
    {
        cout << endl << endl << endl << "Enter Number of Deaths to be searched:  ";
        cin >> Deaths;


        intFoundNode = search(Root_int, Deaths, found);

        if (intFoundNode != NULL)
            RBDisplayRecords(intFoundNode);
    }
    else if (choice == 6)
    {
        cout << endl << endl << endl << "Enter Age-adjusted Death Rate to be searched:  ";
        cin >> Age;

        floatFoundNode = search(Root_float, Age, found);

        if (floatFoundNode != NULL)
            RBDisplayRecords(floatFoundNode);
    }

    ////////////////////////////////////////
    if (stringFoundNode != NULL || intFoundNode != NULL || floatFoundNode != NULL)  // when search successful
    {
        cout << endl << endl << endl;
        cout << " 1. Delete Records" << endl;
        cout << " 2. Update Records" << endl;
        cout << " 3. Exit" << endl << endl << endl;
        cout << "     Enter your choice..........";
        cin >> operation_choice;

        switch (operation_choice)
        {
        case 1:
            if (choice == 1)  // ID
            {
                RBDeleteRecords(intFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/RBID/output.dsdb");
                system("rmdir D:\\Indexed\\RBID");
                Generating_RBTree(choice);
            }


            else if (choice == 2)  //Year
            {
                RBDeleteRecords(intFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/RBYear/output.dsdb");
                system("rmdir D:\\Indexed\\RBYear");
                Generating_RBTree(choice);
            }
            else if (choice == 3 || choice == 4)  // Cause and state
            {
                RBDeleteRecords(stringFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";

                if (choice == 3)
                {
                    remove("D:/Indexed/RBCause/output.dsdb");
                    system("rmdir D:\\Indexed\\RBCause");
                    Generating_RBTree(choice);
                }
                else
                {
                    remove("D:/Indexed/RBState/output.dsdb");
                    system("rmdir D:\\Indexed\\RBState");
                    Generating_RBTree(choice);
                }
            }
            else if (choice == 5)    // deaths
            {
                RBDeleteRecords(intFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/RBDeaths/output.dsdb");
                system("rmdir D:\\Indexed\\RBDeaths");
                Generating_AVLTree(choice);
            }
            else if (choice == 6)  //Age
            {
                RBDeleteRecords(floatFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/RBAge/output.dsdb");
                system("rmdir D:\\Indexed\\RBAge");
                Generating_RBTree(choice);
            }
            break;
        case 2:
            if (choice == 1)
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Year" << endl;
                cout << "2. Cause Name" << endl;
                cout << "3. State" << endl;
                cout << "4. Deaths" << endl;
                cout << "5. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "Year";

                    cout << "Enter Previous Year: ";
                    cin >> Iprev_val;
                    cout << "Enter New Year: ";
                    cin >> Inew_val;
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 2:
                    FieldName = "CauseName";

                    getchar();
                    cout << "Enter Previous Cause: ";
                    getline(cin, Sprev_val);
                    cout << "Enter New Cause: ";
                    getline(cin, Snew_val);
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;

                case 3:
                    FieldName = "State";

                    getchar();
                    cout << "Enter Previous State Name: ";
                    getline(cin, Sprev_val);

                    cout << "Enter New State Name: ";
                    getline(cin, Snew_val);
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;

                case 4:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                case 5:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                }

            }
            else if (choice == 2)
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Cause Name" << endl;
                cout << "2. State" << endl;
                cout << "3. Deaths" << endl;
                cout << "4. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "CauseName";

                    getchar();
                    cout << "Enter Previous Cause: ";
                    getline(cin, Sprev_val);
                    cout << "Enter New Cause: ";
                    getline(cin, Snew_val);
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;

                case 2:
                    FieldName = "State";

                    getchar();
                    cout << "Enter Previous State Name: ";
                    getline(cin, Sprev_val);

                    cout << "Enter New State Name: ";
                    getline(cin, Snew_val);
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;

                case 3:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                case 4:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;
                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                }
            }

            else if (choice == 3)
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Year" << endl;
                cout << "2. State" << endl;
                cout << "3. Deaths" << endl;
                cout << "4. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "Year";

                    cout << "Enter Previous Year: ";
                    cin >> Iprev_val;
                    cout << "Enter New Year: ";
                    cin >> Inew_val;

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 2:
                    FieldName = "State";

                    getchar();
                    cout << "Enter Previous State Name: ";
                    getline(cin, Sprev_val);

                    cout << "Enter New State Name: ";
                    getline(cin, Snew_val);

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 3:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 4:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                }
            }
            else if (choice == 4)    // key is state
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Year" << endl;
                cout << "2. Cause Name" << endl;
                cout << "3. Deaths" << endl;
                cout << "4. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "Year";

                    cout << "Enter Previous Year: ";
                    cin >> Iprev_val;
                    cout << "Enter New Year: ";
                    cin >> Inew_val;

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 2:
                    FieldName = "CauseName";

                    getchar();
                    cout << "Enter Previous Cause: ";
                    getline(cin, Sprev_val);

                    getchar();
                    cout << "Enter New Cause: ";
                    getline(cin, Snew_val);

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 3:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 4:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;

                    RBUpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                }
                system("cls");
                cout << endl << endl << "          Records Updated successfully" << endl << endl;

                Generating_RBTree(choice);

            }
            break;
        default:
            exit(1);
        }

        system("cls");
        cout << endl << endl << "          Records Updated successfully" << endl << endl;

        Generating_RBTree(choice);
    }
}

// function overloading
void Searching_AVLTree(int choice, AVLNode<float>* Root_float, AVLNode<string>* Root_string, AVLNode<int>* Root_int, char Rch)  // indexing choice, root of all types
{
    bool found = false;

    AVLNode<int>* intFoundNode = NULL;
    AVLNode<string>* stringFoundNode = NULL;
    AVLNode<float>* floatFoundNode = NULL;

    int id1, id2; // between these ranges
    int year1, year2;
    int death1, death2;
    float age1, age2;

    if (choice == 1)
    {
        cout << endl << endl << endl << "Enter Range for IDs to be searched:  ";
        cout << "Range1: ";
        cin >> id1;
        cout << "Range2: ";
        cin >> id2;

        for (int i = id1; i <= id2; i++)  // loop from id1 to id2
        {
            intFoundNode = Search(Root_int, i, found);

            if (intFoundNode != NULL)
                DisplayRecords(intFoundNode);
        }
    }

    else if (choice == 2)
    {
        cout << endl << endl << endl << "Enter Range for Years to be searched:  ";
        cout << "Range1: ";
        cin >> year1;
        cout << "Range2: ";
        cin >> year2;
        for (int i = year1; i <= year2; i++)  // will search btw these years
        {
            intFoundNode = Search(Root_int, i, found);

            if (intFoundNode != NULL)
                DisplayRecords(intFoundNode);
        }
    }



    else if (choice == 5)
    {
        cout << endl << endl << endl << "Enter Range for Ages to be searched:  ";
        cout << "Range1: ";
        cin >> death1;
        cout << "Range2: ";
        cin>> death2;
        for (int i = death1; i <= death2; i++)  // will search btw these ages
        {
            intFoundNode =
                Search(Root_int, i, found);

            if (intFoundNode != NULL)
                DisplayRecords(intFoundNode);
        }
    }

    else if (choice == 6)
    {
        cout << endl << endl << endl << "Enter Range for Ages to be searched:  ";
      cout << "Range1: ";
        cin >> age1;
        cout << "Range2: ";
        cin>> age2;

        for (float i = age1; i <= age2; i++)  // will search btw these ages
        {
            floatFoundNode = Search(Root_float, i, found);

            if (floatFoundNode != NULL)
                DisplayRecords(floatFoundNode);
        }
    }
}

void Searching_AVLTree(int choice, AVLNode<float>* Root_float, AVLNode<string>* Root_string, AVLNode<int>* Root_int)  // choice passed here
{
    string stateName, cause;
    int ID, Year, Deaths;
    float Age;
    bool found = false;
    int operation_choice;

    AVLNode<int>* intFoundNode = NULL;
    AVLNode<string>* stringFoundNode = NULL;
    AVLNode<float>* floatFoundNode = NULL;

    int Field_Choice;
    string FieldName = "";

    int Iprev_val = 0, Inew_val = 0;
    string Sprev_val = "", Snew_val = "";
    float Fprev_val = 0, Fnew_val = 0;

    if (choice == 1)  // ID
    {
        cout << endl << endl << endl << "Enter ID to be searched:  ";
        cin >> ID;

        intFoundNode = Search(Root_int, ID, found);  // new node address returned (that was being searched)

        if (intFoundNode != NULL)
            DisplayRecords(intFoundNode);
    }
    else if (choice == 2)
    {
        cout << endl << endl << endl << "Enter Year to be searched:  ";
        cin >> Year;

        intFoundNode = Search(Root_int, Year, found);

        if (intFoundNode != NULL)
            DisplayRecords(intFoundNode);

    }
    else if (choice == 3)
    {
        getchar();

        cout << endl << endl << endl << "Enter Cause to be searched:  ";
        getline(cin, cause);
        stringFoundNode = Search(Root_string, cause, found);

        if (stringFoundNode != NULL)
            DisplayRecords(stringFoundNode);

    }
    else if (choice == 4)
    {
        getchar();

        cout << endl << endl << endl << "Enter name of state to be searched:  ";
        getline(cin, stateName);

        cout << endl << endl;
        stringFoundNode = Search(Root_string, stateName, found);

        if (stringFoundNode != NULL)
            DisplayRecords(stringFoundNode);

    }
    else if (choice == 5)
    {
        cout << endl << endl << endl << "Enter Number of Deaths to be searched:  ";
        cin >> Deaths;


        intFoundNode = Search(Root_int, Deaths, found);

        if (intFoundNode != NULL)
            DisplayRecords(intFoundNode);
    }
    else if (choice == 6)
    {
        cout << endl << endl << endl << "Enter Age-adjusted Death Rate to be searched:  ";
        cin >> Age;

        floatFoundNode = Search(Root_float, Age, found);

        if (floatFoundNode != NULL)
            DisplayRecords(floatFoundNode);
    }

    ////////////////////////////////////////
    if (stringFoundNode != NULL || intFoundNode != NULL || floatFoundNode != NULL)  // when search successful
    {
        cout << endl << endl << endl;
        cout << " 1. Delete Records" << endl;
        cout << " 2. Update Records" << endl;
        cout << " 3. Exit" << endl << endl << endl;
        cout << "     Enter your choice..........";
        cin >> operation_choice;

        switch (operation_choice)
        {
        case 1:
            if (choice == 1)  // ID
            {
                DeleteRecords(intFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/AVLID/output.dsdb");
                system("rmdir D:\\Indexed\\AVLID");
                Generating_AVLTree(choice);
            }


            else if (choice == 2)  //Year
            {
                DeleteRecords(intFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/AVLYear/output.dsdb");
                system("rmdir D:\\Indexed\\AVLYear");
                Generating_AVLTree(choice);
            }
            else if (choice == 3 || choice == 4)  // Cause and state
            {
                DeleteRecords(stringFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";

                if (choice == 3)
                {
                    remove("D:/Indexed/AVLCause/output.dsdb");
                    system("rmdir D:\\Indexed\\AVLCause");
                    Generating_AVLTree(choice);
                }
                else
                {
                    remove("D:/Indexed/AVLState/output.dsdb");
                    system("rmdir D:\\Indexed\\AVLState");
                    Generating_AVLTree(choice);
                }
            }
            else if (choice == 5)    // deaths
            {
                DeleteRecords(intFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/AVLDeaths/output.dsdb");
                system("rmdir D:\\Indexed\\AVLDeaths");
                Generating_AVLTree(choice);
            }
            else if (choice == 6)  //Age
            {
                DeleteRecords(floatFoundNode, choice);
                cout << endl << endl << "          Records deleted successfully";
                remove("D:/Indexed/AVLAge/output.dsdb");
                system("rmdir D:\\Indexed\\AVLAge");
                Generating_AVLTree(choice);
            }
            break;
        case 2:
            if (choice == 1)
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Year" << endl;
                cout << "2. Cause Name" << endl;
                cout << "3. State" << endl;
                cout << "4. Deaths" << endl;
                cout << "5. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "Year";

                    cout << "Enter Previous Year: ";
                    cin >> Iprev_val;
                    cout << "Enter New Year: ";
                    cin >> Inew_val;
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 2:
                    FieldName = "CauseName";

                    getchar();
                    cout << "Enter Previous Cause: ";
                    getline(cin, Sprev_val);
                    cout << "Enter New Cause: ";
                    getline(cin, Snew_val);
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;

                case 3:
                    FieldName = "State";

                    getchar();
                    cout << "Enter Previous State Name: ";
                    getline(cin, Sprev_val);

                    cout << "Enter New State Name: ";
                    getline(cin, Snew_val);
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;

                case 4:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                case 5:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                }

            }
            else if (choice == 2)
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Cause Name" << endl;
                cout << "2. State" << endl;
                cout << "3. Deaths" << endl;
                cout << "4. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "CauseName";

                    getchar();
                    cout << "Enter Previous Cause: ";
                    getline(cin, Sprev_val);
                    cout << "Enter New Cause: ";
                    getline(cin, Snew_val);
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;

                case 2:
                    FieldName = "State";

                    getchar();
                    cout << "Enter Previous State Name: ";
                    getline(cin, Sprev_val);

                    cout << "Enter New State Name: ";
                    getline(cin, Snew_val);
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;

                case 3:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                case 4:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;
                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);
                    break;
                }
            }

            else if (choice == 3)
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Year" << endl;
                cout << "2. State" << endl;
                cout << "3. Deaths" << endl;
                cout << "4. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "Year";

                    cout << "Enter Previous Year: ";
                    cin >> Iprev_val;
                    cout << "Enter New Year: ";
                    cin >> Inew_val;

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 2:
                    FieldName = "State";

                    getchar();
                    cout << "Enter Previous State Name: ";
                    getline(cin, Sprev_val);

                    cout << "Enter New State Name: ";
                    getline(cin, Snew_val);

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 3:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 4:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                }
            }
            else if (choice == 4)    // key is state
            {
                cout << "  Which field do you want to Update?" << endl << endl;
                cout << "1. Year" << endl;
                cout << "2. Cause Name" << endl;
                cout << "3. Deaths" << endl;
                cout << "4. Age-adjusted Death Rate" << endl << endl;
                cout << "      Enter your choice.........";
                cin >> Field_Choice;
                switch (Field_Choice)
                {
                case 1:
                    FieldName = "Year";

                    cout << "Enter Previous Year: ";
                    cin >> Iprev_val;
                    cout << "Enter New Year: ";
                    cin >> Inew_val;

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 2:
                    FieldName = "CauseName";

                    getchar();
                    cout << "Enter Previous Cause: ";
                    getline(cin, Sprev_val);

                    getchar();
                    cout << "Enter New Cause: ";
                    getline(cin, Snew_val);

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 3:
                    FieldName = "Deaths";

                    cout << "Enter Previous Value: ";
                    cin >> Iprev_val;
                    cout << "Enter New Value: ";
                    cin >> Inew_val;

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                case 4:
                    FieldName = "Age";

                    cout << "Enter Previous Value: ";
                    cin >> Fprev_val;
                    cout << "Enter New Value: ";
                    cin >> Fnew_val;

                    UpdateRecords(intFoundNode, floatFoundNode, stringFoundNode, choice, FieldName, Iprev_val, Inew_val, Sprev_val, Snew_val, Fprev_val, Fnew_val);

                    break;
                }
                system("cls");
                cout << endl << endl << "          Records Updated successfully" << endl << endl;

                Generating_AVLTree(choice);

            }
            break;
        default:
            exit(1);
        }

        system("cls");
        cout << endl << endl << "          Records Updated successfully" << endl << endl;

        Generating_AVLTree(choice);
    }
    //////////////////////////////////////
}

void Generating_RBTree(int choice) {
    Node<float>* Root_float = NULL; //deathrate
    Node<string>* Root_string = NULL;  //cause,state
    Node<int>* Root_int = NULL;  //year,id,deaths

    char ch;

    if (choice == 3 || choice == 4)
        Root_string = NULL;   // initialize
    else if (choice == 6)
        Root_float = NULL;
    else
        Root_int = NULL;

    RBCreateDirectory(choice);   // Create folder 

    fstream input;
    string filename, line;
    int LineNo;
    int c = 0;
    DeathCauses record;

    for (int i = 1; i <= 2; i++)  // to read all 10 files
    {

        LineNo = 0;
        filename = "C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(i) + ".csv";

        input.open(filename, ios::in);
        if (!input)
            cout << "Can't open file";

        else
        {
            getline(input, line);   // reads heading
            LineNo++;  // next line
            while (getline(input, line))  // reads till end of file
            {
                ReadTuple(line, &record);  // calling func of filing
                LineNo++;

                if (choice == 3 || choice == 4)  // key is chosen from here..on that basis indexing is done
                {
                    if (choice == 3)
                        Root_string = insert(Root_string, record.CauseName, true, filename, LineNo, record.ID); // tree creation
                    else
                        Root_string = insert(Root_string, record.State, true, filename, LineNo, record.ID);
                }
                else if (choice == 6)
                {
                    Root_float = insert(Root_float, record.Age, filename, LineNo, record.ID);
                }
                else
                {
                    if (choice == 1) {
                        if (c == 300)
                            break;
                        Root_int = insert(Root_int, record.ID, filename, LineNo, record.ID);
                        c++;
                    }
                    else if (choice == 5)
                        Root_int = insert(Root_int, record.Deaths, filename, LineNo, record.ID);
                    else
                        Root_int = insert(Root_int, record.Year, filename, LineNo, record.ID);
                }
            }
            input.close();
        }
    }

    if (choice == 3 || choice == 4)
        inorder_Traversal(Root_string, choice);
    else if (choice == 6)
        inorder_Traversal(Root_float, choice);
    else
        inorder_Traversal(Root_int, choice);
    cout << endl << endl << " Index Created Successfully" << endl << endl << endl;   // indexes created

    system("pause"); // will continue on key pressed

    system("cls");   // screen cleared
    cout << endl << endl << endl << "Do you want to perform Searching(y/n)?";
    cin >> ch;
    char Rchoice;  // another var

    cout << "Do you want to perform Range Searching: (y/n): ";
    cin >> Rchoice;
    if (Rchoice == 'y' || Rchoice == 'Y')
    {
        Searching_RBTree(choice, Root_float, Root_string, Root_int, Rchoice);  // jumps to range search func
    }
    else

    {
        while (ch == 'y' || ch == 'Y')
        {
            system("cls");
            Searching_RBTree(choice, Root_float, Root_string, Root_int);
            cout << endl << endl << endl << "Do you want to Search again(y/n)?";
            cin >> ch;
        }
    }
    exit(1);
}

void Generating_AVLTree(int choice)
{
    AVLNode<float>* Root_float = NULL; //deathrate
    AVLNode<string>* Root_string = NULL;  //cause,state
    AVLNode<int>* Root_int = NULL;  //year,id,deaths

    char ch;

    if (choice == 3 || choice == 4)  // cause and state... string choices
        Root_string = NULL;   // initialize
    else if (choice == 6)
        Root_float = NULL;
    else
        Root_int = NULL;

    CreateDirectory(choice);   // Create folder 

    fstream input;
    string filename, line;
    int LineNo;

    DeathCauses record;

    for (int i = 1; i <= 2; i++)  // to read all 10 files
    {

        LineNo = 0;
        filename = "C:\\Users\\u6yg\\source\\repos\\DS__Project\\datafiles\\NCHS_-_Leading_Causes_of_Death__United_States_" + to_string(i) + ".csv";

        input.open(filename, ios::in);
        if (!input)
            cout << "Can't open file";

        else
        {
            getline(input, line);   // reads heading
            LineNo++;  // next line
            while (getline(input, line))  // reads till end of file
            {
                ReadTuple(line, &record);  // calling func of filing
                LineNo++;

                if (choice == 3 || choice == 4)  // key is chosen from here..on that basis indexing is done
                {
                    if (choice == 3)
                        Root_string = Insert(Root_string, record.CauseName, filename, LineNo, record.ID); // tree creation
                    else
                        Root_string = Insert(Root_string, record.State, filename, LineNo, record.ID);
                }
                else if (choice == 6)
                {
                    Root_float = Insert(Root_float, record.Age, filename, LineNo, record.ID);
                }
                else
                {
                    if (choice == 1)
                        Root_int = Insert(Root_int, record.ID, filename, LineNo, record.ID);
                    else if (choice == 5)
                        Root_int = Insert(Root_int, record.Deaths, filename, LineNo, record.ID);
                    else
                        Root_int = Insert(Root_int, record.Year, filename, LineNo, record.ID);
                }
            }
            input.close();
        }
    }

    if (choice == 3 || choice == 4)
        Inorder_Traversal(Root_string, choice);
    else if (choice == 6)
        Inorder_Traversal(Root_float, choice);
    else
        Inorder_Traversal(Root_int, choice);
    cout << endl << endl << " Index Created Successfully" << endl << endl << endl;   // indexes created

    system("pause"); // will continue on key pressed

    system("cls");   // screen cleared
    cout << endl << endl << endl << "Do you want to perform Searching(y/n)?";
    cin >> ch;

    char Rchoice;  // another var

    cout << "Do you want to perform Range Searching: (y/n): ";
    cin >> Rchoice;
    if (Rchoice == 'y' || Rchoice == 'Y')
    {
        Searching_AVLTree(choice, Root_float, Root_string, Root_int, Rchoice);  // jumps to range search func
    }
    else

    {
        while (ch == 'y' || ch == 'Y')
        {
            system("cls");
            Searching_AVLTree(choice, Root_float, Root_string, Root_int);
            cout << endl << endl << endl << "Do you want to Search again(y/n)?";
            cin >> ch;
        }
    }
    exit(1);
}


int main()
{
    char ch;
    int choice, TreeChoice;

    cout << "\t\t\t*|====================================================|*\n";
    cout << "\t\t\t||                                                    ||\n";
    cout << "\t\t\t||                DSDB : FILE INDEXING SYSTEM         ||\n";
    cout << "\t\t\t||                                                    ||\n";
    cout << "\t\t\t*|====================================================|*\n\n";
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "                                *************   Tree Menu    *************" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl << endl;

    cout << "\t1.  B-Tree" << endl;
    cout << "\t2.  AVL-Tree" << endl;
    cout << "\t3.  Red-Black-Tree" << endl;
    cout << "Enter your Choice....... : ";
    cin >> TreeChoice;

    system("cls");
    cout << endl << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "                                *************   Index Menu    *************" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl << endl;
    cout << "Index By Using: " << endl;
    cout << "1.   ID" << endl;
    cout << "2.   Year" << endl;
    cout << "3.   Cause" << endl;
    cout << "4.   State" << endl;
    cout << "5.   No of Deaths" << endl;
    cout << "6.   Age" << endl;
    cout << "Enter your Choice....... : ";
    cin >> choice;

    switch (TreeChoice)
    {
    case 1:

        break;
    case 2:
        Generating_AVLTree(choice);

        break;
    case 3:
        Generating_RBTree(choice);
        break;
    }
}