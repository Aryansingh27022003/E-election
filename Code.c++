#include <iostream>
#include<fstream>
#include<limits>
#include<map>
using namespace std;
class candidate
{
public:
  string name;
  string sch_id;
  string department;

  void Manifesto ()
  {
    std::string notice;
    std::ofstream outfile;
    std::cout << "Write your Manifesto here: ";
    std::cin.ignore (std::numeric_limits < std::streamsize >::max (), '\n');
    std::getline (std::cin, notice);
    outfile.open ("Manifesto by candidate 1.txt", std::ios::trunc);
    outfile << notice;

    outfile.close ();
  }
  void view_notice ()
  {
    std::ifstream file ("Notice by dean.txt");
    std::string notice_dean;
    if (file.is_open ())
      {
	while (std::getline (file, notice_dean))
	  {
	    std::cout << notice_dean << std::endl;
	  }
	file.close ();
      }
    else
      {
	std::cout << "Unable to open file" << std::endl;
      }
  }
  
   void view_manifesto ()
  {
    std::ifstream file ("Manifesto by candidate 1.txt");
    std::string notice_dean;
    if (file.is_open ())
      {
	while (std::getline (file, notice_dean))
	  {
	    std::cout << notice_dean << std::endl;
	  }
	file.close ();
      }
    else
      {
	std::cout << "Unable to open file" << std::endl;
      }
  }
  

};

class Nitadministration
{
public:
  int dean;
    map < string, string > details;
  string del;

  void notice ()
  {
    std::string notice;
    std::ofstream outfile;
    std::cout << "Write your notice here:";
    std::cin.ignore (std::numeric_limits < std::streamsize >::max (), '\n');
    std::getline (std::cin, notice);
    outfile.open ("Notice by dean.txt", std::ios::trunc);
    outfile << notice;

    outfile.close ();
  }
  void nomination ()
  {
    cout << "Enter your name:";
    string key, value;
    cin >> key;
    cout << "Enter your scholar id:";
    cin >> value;
    details[key] = value;

    cout << "choose the post you are standing for:" << endl;
    cout << "1.Vice President" << endl;
    cout << "2.General Secretary" << endl;
    cout << "3.General Secretary(technical)" << endl;
    cout << "4.General Secretary(cultural)" << endl;
    cout << "5.General Secretary(Sports)" << endl;
    cout << "Write the correct option:";
    int k;
    cin >> k;
    ofstream file;
    ofstream fout;
    switch (k)
      {
      case 1:

	fout.open ("vp_details.txt", ios::app);
	while (fout)
	  {
	    ifstream fin;
	    fin.open ("vp_details.txt");
	    for (auto it = details.begin (); it != details.end (); it++)
	      {
		fout << it->first << "=" << it->second << endl;
	      }
	    cout << "Your application has been succcessfully submitted." <<
	      endl;
	    break;
	  }
	fout.close ();
	break;
      case 2:
	fout.open ("gs_details.txt", ios::app);
	while (fout)
	  {
	    ifstream fin;
	    fin.open ("gs_details.txt");
	    for (auto it = details.begin (); it != details.end (); it++)
	      {
		fout << it->first << "=" << it->second << endl;
	      }
	    cout << "Your application has been succcessfully submitted." <<
	      endl;
	    break;
	  }
	fout.close ();
	break;
      case 3:
	fout.open ("gs(technical)_details.txt", ios::app);
	while (fout)
	  {
	    ifstream fin;
	    fin.open ("gs(technical)_details.txt");
	    for (auto it = details.begin (); it != details.end (); it++)
	      {
		fout << it->first << "=" << it->second << endl;
	      }
	    cout << "Your application has been succcessfully submitted." <<
	      endl;
	    break;
	  }
	fout.close ();
	break;
      case 4:
	fout.open ("gs(cultural)_details.txt", ios::app);
	while (fout)
	  {
	    ifstream fin;
	    fin.open ("gs(cultural)_details.txt");
	    for (auto it = details.begin (); it != details.end (); it++)
	      {
		fout << it->first << "=" << it->second << endl;
	      }
	    cout << "Your application has been succcessfully submitted." <<
	      endl;
	    break;
	  }
	fout.close ();
	break;
      case 5:
	fout.open ("gs(sports)_details.txt", ios::app);
	while (fout)
	  {
	    ifstream fin;
	    fin.open ("gs(sports)_details.txt");
	    for (auto it = details.begin (); it != details.end (); it++)
	      {
		fout << it->first << "=" << it->second << endl;
	      }
	    cout << "Your application has been succcessfully submitted." <<
	      endl;
	    break;
	  }
	fout.close ();
	break;

      }
  }

  void withdraw_name ()
  {
    cout << "Enter your name and scholar id as(name=sch_id): ";
    string key;
    cin >> key;
    cout << "choose the post:" << endl;
    cout << "1.Vice President" << endl;
    cout << "2.General Secretary" << endl;
    cout << "3.General Secretary(technical)" << endl;
    cout << "4.General Secretary(cultural)" << endl;
    cout << "5.General Secretary(Sports)" << endl;
    cout << "Write the correct option:";
    int k;
    cin >> k;
    switch (k)
      {
      case 1:
	{
	  std::ifstream inFile ("vp_details.txt");
	  std::ofstream tempFile ("temp.txt");
	  std::string line;
	  std::string contentToDelete = key;

	  while (getline (inFile, line))
	    {
	      if (line.find (contentToDelete) != std::string::npos)
		{
		  // Skip writing the line to the temporary file
		  continue;
		}

	      // Write the line to the temporary file
	      tempFile << line << std::endl;
	    }
	  inFile.close ();
	  tempFile.close ();
	  if (std::remove ("vp_details.txt") != 0)
	    {
	      std::cout << "Error deleting file" << std::endl;
	    }
	  if (std::rename ("temp.txt", "vp_details.txt") != 0)
	    {
	      std::cout << "Error renaming file" << std::endl;
	    }
	  break;
	}
      case 2:
	{

	  std::ifstream inFile ("gs_details.txt");
	  std::ofstream tempFile ("temp.txt");
	  std::string line;
	  std::string contentToDelete = key;

	  while (getline (inFile, line))
	    {
	      if (line.find (contentToDelete) != std::string::npos)
		{
		  // Skip writing the line to the temporary file
		  continue;
		}

	      // Write the line to the temporary file
	      tempFile << line << std::endl;
	    }
	  inFile.close ();
	  tempFile.close ();
	  if (std::remove ("gs_details.txt") != 0)
	    {
	      std::cout << "Error deleting file" << std::endl;
	    }
	  if (std::rename ("temp.txt", "gs_details.txt") != 0)
	    {
	      std::cout << "Error renaming file" << std::endl;
	    }
	  break;
	}
      case 3:
	{
	  std::ifstream inFile ("gs(technical)_details.txt");
	  std::ofstream tempFile ("temp.txt");
	  std::string line;
	  std::string contentToDelete = key;

	  while (getline (inFile, line))
	    {
	      if (line.find (contentToDelete) != std::string::npos)
		{
		  // Skip writing the line to the temporary file
		  continue;
		}

	      // Write the line to the temporary file
	      tempFile << line << std::endl;
	    }
	  inFile.close ();
	  tempFile.close ();
	  if (std::remove ("gs(technical)_details.txt") != 0)
	    {
	      std::cout << "Error deleting file" << std::endl;
	    }
	  if (std::rename ("temp.txt", "gs(technical)_details.txt") != 0)
	    {
	      std::cout << "Error renaming file" << std::endl;
	    }
	  break;
	}
      case 4:
	{
	  std::ifstream inFile ("gs(cultural)_details.txt");
	  std::ofstream tempFile ("temp.txt");
	  std::string line;
	  std::string contentToDelete = key;

	  while (getline (inFile, line))
	    {
	      if (line.find (contentToDelete) != std::string::npos)
		{
		  // Skip writing the line to the temporary file
		  continue;
		}

	      // Write the line to the temporary file
	      tempFile << line << std::endl;
	    }
	  inFile.close ();
	  tempFile.close ();
	  if (std::remove ("gs(cultural)_details.txt") != 0)
	    {
	      std::cout << "Error deleting file" << std::endl;
	    }
	  if (std::rename ("temp.txt", "gs(cultural)_details.txt") != 0)
	    {
	      std::cout << "Error renaming file" << std::endl;
	    }
	  break;
	}
      case 5:
	{
	  std::ifstream inFile ("gs(sports)_details.txt");
	  std::ofstream tempFile ("temp.txt");
	  std::string line;
	  std::string contentToDelete = key;

	  while (getline (inFile, line))
	    {
	      if (line.find (contentToDelete) != std::string::npos)
		{
		  // Skip writing the line to the temporary file
		  continue;
		}

	      // Write the line to the temporary file
	      tempFile << line << std::endl;
	    }
	  inFile.close ();
	  tempFile.close ();
	  if (std::remove ("gs(sports)_details.txt") != 0)
	    {
	      std::cout << "Error deleting file" << std::endl;
	    }
	  if (std::rename ("temp.txt", "gs(sports)_details.txt") != 0)
	    {
	      std::cout << "Error renaming file" << std::endl;
	    }
	  break;
	}
      }
  }
  void view_vp ()
  {
    std::ifstream file ("vp_details.txt");
    std::string notice_dean;
    if (file.is_open ())
      {
	while (std::getline (file, notice_dean))
	  {
	    std::cout << notice_dean << std::endl;
	  }
	file.close ();
      }
    else
      {
	std::cout << "Unable to open file" << std::endl;
      }
  }
  void view_gs ()
  {
    std::ifstream file ("gs_details.txt");
    std::string notice_dean;
    if (file.is_open ())
      {
	while (std::getline (file, notice_dean))
	  {
	    std::cout << notice_dean << std::endl;
	  }
	file.close ();
      }
    else
      {
	std::cout << "Unable to open file" << std::endl;
      }
  }
  void view_gs_cultural ()
  {
    std::ifstream file ("gs(cultural)_details.txt");
    std::string notice_dean;
    if (file.is_open ())
      {
	while (std::getline (file, notice_dean))
	  {
	    std::cout << notice_dean << std::endl;
	  }
	file.close ();
      }
    else
      {
	std::cout << "Unable to open file" << std::endl;
      }
  }
  void view_gs_sports ()
  {
    std::ifstream file ("gs(sports)_details.txt");
    std::string notice_dean;
    if (file.is_open ())
      {
	while (std::getline (file, notice_dean))
	  {
	    std::cout << notice_dean << std::endl;
	  }
	file.close ();
      }
    else
      {
	std::cout << "Unable to open file" << std::endl;
      }
  }
  void view_gs_technical ()
  {
    std::ifstream file ("gs(technical)_details.txt");
    std::string notice_dean;
    if (file.is_open ())
      {
	while (std::getline (file, notice_dean))
	  {
	    std::cout << notice_dean << std::endl;
	  }
	file.close ();
      }
    else
      {
	std::cout << "Unable to open file" << std::endl;
      }
  }
void result(){
  	  int j;
	  cout << "Choose the post you want review" << endl;
	  cout << "1.Vice President" << endl;
	  cout << "2.General Secretary" << endl;
	  cout << "3.General Secretary(Cultural)" << endl;
	  cout << "4.General Secretary(Sports)" << endl;
	  cout << "5.General Secretary(Technical)" << endl;
	  cin >> j;
	  switch (j)
	    {
	     case 1:{
	     cout<<"Total vote for candidate 1 is";
std::ifstream file ("candidate1vp.txt");
std::string notice_dean;
if (file.is_open ())
{
    while (std::getline (file, notice_dean))
    {
        std::cout << notice_dean << std::endl;
    }
    file.close ();
}
else
{
    std::cout << "Unable to open file" << std::endl;
}

cout<<"Total vote for candidate 2 is";
std::ifstream file2 ("candidate2vp.txt");
std::string notice_dean1;
if (file2.is_open ())
{
    while (std::getline (file2, notice_dean1))
    {
        std::cout << notice_dean1 << std::endl;
    }
    file2.close ();
}
else
{
    std::cout << "Unable to open file" << std::endl;
}

if(notice_dean1 > notice_dean){
    cout << "Candidate 2 is winner by " << std::stoi(notice_dean1) - std::stoi(notice_dean) << " votes" << endl;
}
else{
    cout << "Candidate 1 is winner by " << std::stoi(notice_dean) - std::stoi(notice_dean1) << " votes" << endl;
}
break;
}
 case 2:{
 cout<<"Total vote for candidate 1 is";
std::ifstream file ("candidate1gs.txt");
std::string notice_dean;
if (file.is_open ())
{
    while (std::getline (file, notice_dean))
    {
        std::cout << notice_dean << std::endl;
    }
    file.close ();
}
else
{
    std::cout << "Unable to open file" << std::endl;
}

cout<<"Total vote for candidate 2 is";
std::ifstream file2 ("candidate2gs.txt");
std::string notice_dean1;
if (file2.is_open ())
{
    while (std::getline (file2, notice_dean1))
    {
        std::cout << notice_dean1 << std::endl;
    }
    file2.close ();
}
else
{
    std::cout << "Unable to open file" << std::endl;
}

if(notice_dean1 > notice_dean){
    cout << "Candidate 2 is winner by " << std::stoi(notice_dean1) - std::stoi(notice_dean) << " votes" << endl;
}
else{
    cout << "Candidate 1 is winner by " << std::stoi(notice_dean) - std::stoi(notice_dean1) << " votes" << endl;
}
}
}
	    
  }
};

class voterlist
{
public:
  //string password;
  string line;
  int n;
  void vp_voter ()
  {
      string password;
    ofstream fout;
      fout.open ("vp_voter.txt", ios::app);
    while (fout)
      {
	cout << "Enter your scholar id" << endl;
	cin >> password;
	ifstream fin;
	  fin.open ("vp_voter.txt");
	while (getline (fin, line))
	  {
	    if (password == line)
	      {
		n = 1;
		break;
	      }
	  }
	if (n == 1)
	  {
	    cout << "You can't vote" << endl;
	    n=0;
	  }
	else
	  {
	    fout << password << endl;
	    cout << "Thank you for voting." << endl;
	    break;
	  }
      }
    fout.close ();
    //break;




  }

void gs_voter() {
   
    ofstream fout;
    fout.open("gs_voter.txt", ios::app);
    bool unique_id = false; // flag to keep track of unique ID
    string password; // declare password outside of the while loop
    while (!unique_id) {
        cout << "Enter your scholar ID" << endl;
        cin >> password;
        ifstream fin;
        fin.open("gs_voter.txt");
        bool match_found = false;
        string line;
        while (getline(fin, line)) {
            if (password == line) {
                match_found = true;
                break;
            }
        }
        fin.close();
        if (match_found) {
            cout << "You can't vote" << endl;
        }
        else {
            fout << password << endl;
            cout << "Thank you for voting." << endl;
            exit;
            unique_id = true; // set flag to exit loop
        }
        if(unique_id){
         break;
        }
    }
    fout.close();
}

  void gs_cultural_voter ()
  {
    string password;
    ofstream fout;
      fout.open ("gs_cultural_voter.txt", ios::app);
    while (fout)
      {
	cout << "Enter your scholar id" << endl;
	cin >> password;
	ifstream fin;
	  fin.open ("gs_cultural_voter.txt");
	while (getline (fin, line))
	  {
	    if (password == line)
	      {
		n = 1;
		break;
	      }
	  }
	if (n == 1)
	  {
	    cout << "You can't vote" << endl;
	    n=0;
	  }
	else
	  {
	    fout << password << endl;
	    cout << "Thank you for voting2." << endl;
	    break;
	  }
	  break;
      }
    fout.close ();
    //break;




  }
  void gs_sports_voter ()
  {
    string password;
    ofstream fout;
      fout.open ("gs_sports_voter.txt", ios::app);
    while (fout)
      {
	cout << "Enter your scholar id" << endl;
	cin >> password;
	ifstream fin;
	  fin.open ("gs_sports_voter.txt");
	while (getline (fin, line))
	  {
	    if (password == line)
	      {
		n = 1;
		break;
	      }
	  }
	if (n == 1)
	  {
	    cout << "You can't vote" << endl;
	    n=0;
	  }
	else
	  {
	    fout << password << endl;
	    cout << "Thank you for voting." << endl;
	    break;
	  }
      }
    fout.close ();
    //break;




  }
  void gs_technical_voter ()
  {
    string password;
    ofstream fout;
      fout.open ("gs_technical_voter.txt", ios::app);
    while (fout)
      {
	cout << "Enter your scholar id" << endl;
	cin >> password;
	ifstream fin;
	  fin.open ("gs_technical_voter.txt");
	while (getline (fin, line))
	  {
	    if (password == line)
	      {
		n = 1;
		break;
	      }
	  }
	if (n == 1)
	  {
	    cout << "You can't vote" << endl;
	    n=0;
	  }
	else
	  {
	    fout << password << endl;
	    cout << "Thank you for voting." << endl;
	    break;
	  }
      }
    fout.close ();
    //break;




  }
};

class castvote:public Nitadministration, public voterlist
{
public:
  int vote;
  string scholar_id;

  void vote1 ()
  {
    int p;
      cout << "Choose the post you for which you want to vote:" << endl;
      cout << "1.Vice President" << endl;
      cout << "2.General Secretary" << endl;
      cout << "3.General Secretary(Cultural)" << endl;
      cout << "4.General Secretary(Sports)" << endl;
      cout << "5.General Secretary(Technical)" << endl;
      cin >> p;
    switch (p)
      {
      case 1:
	{
	  cout << "Choose the person to whom you want to vote" << endl;
	  view_vp ();
	  string sch_id;
	  int y;
	 
	    cin >> y;

	  if (y == 1)
	    {
	      vp_voter ();
       std::fstream counter_file("candidate1vp.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	    if(y==2){
	     
       vp_voter ();
       std::fstream counter_file("candidate2vp.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	    
	  break;
	}
      case 2:
	{
	  cout << "Choose the person to whom you want to vote" << endl;
	  view_gs ();
	  int y;
	  string sch_id;
	    cin >> y;

	  if (y == 1)
	    {
	      
       gs_voter ();
       std::fstream counter_file("candidate1gs.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	    if(y==2){
	     
       gs_voter ();
       std::fstream counter_file("candidate2gs.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	  break;
	}
      case 3:
	{
	  cout << "Choose the person to whom you want to vote" << endl;
	  view_gs_cultural ();
	  int y;
	  string sch_id;
	    cin >> y;
	    	 gs_cultural_voter ();
	       std::ofstream counter_file("candidate1gscultural.txt");
       counter_file << "0";
       counter_file.close();
       
        std::ofstream counter_file1("candidate2gscultural.txt");
       counter_file << "0";
       counter_file.close();
       
       
	  if (y == 1)
	    {
	      
       gs_cultural_voter ();
       std::fstream counter_file("candidate1gscultural.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	    if(y==2){
	    
       gs_cultural_voter ();
       std::fstream counter_file("candidate2gscultural.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	  break;
	}
      case 4:
	{
	  cout << "Choose the person to whom you want to vote" << endl;
	  view_gs_sports ();
	  int y;
	  string sch_id;
	    cin >> y;
	    
	    	 std::ofstream counter_file("candidate1gssports.txt");
       counter_file << "0";
       counter_file.close();
       
       std::ofstream counter_file1("candidate2gssports.txt");
       counter_file << "0";
       counter_file.close();
       
	    	 
	  if (y == 1)
	    {

	      gs_sports_voter ();
       std::fstream counter_file("candidate1gssports.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	    if(y==2){

       gs_sports_voter ();
       std::fstream counter_file("candidate2gssports.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	  break;
	}
      case 5:
	{
	  cout << "Choose the person to whom you want to vote" << endl;
	  view_gs_technical ();
	  int y;
	  string sch_id;
	    cin >> y;
	    	 std::ofstream counter_file("candidate1gstechnical.txt");
       counter_file << "0";
       counter_file.close();	
       
       std::ofstream counter_file1("candidate2gstechnical.txt");
       counter_file << "0";
       counter_file.close();
       
	  if (y == 1)
	    {

       gs_technical_voter ();
       std::fstream counter_file("candidate1gstechnical.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	    if(y==2){

       gs_technical_voter ();
       std::fstream counter_file("candidate2gstechnical.txt");
       int current_value;
       counter_file >> current_value;
       int new_value = current_value + 1;
       counter_file.seekg(0);
       counter_file << new_value;
       counter_file.close();
	    }
	  break;
	}

      }
  }
};

int
main ()
{
  int option;
  cout << "1.NIT Administration." << endl;
  cout << "2.Candidate." << endl;
  cout << "3.Voter." << endl;
  cout << "Write the option number:";
  cin >> option;
  for (int i = 0; i < 1000; i++)
    {
      if (option != 1 && option != 2 && option != 3)
	{
	  cout << "You have chosen wrong option" << endl;
	  cout << "1.NIT Administration." << endl;
	  cout << "2.Candidate." << endl;
	  cout << "3.Voter." << endl;
	  cout << "Write the option number:-" << endl;
	  cin >> option;
	  cout << "Enter correct option:";
	}
    }
  Nitadministration obj1;
  candidate obj2;
  castvote obj3;

  switch (option)
    {
    case 1:
      int k;
      cout << "1.Want to release notice?" << endl;
      cout << "2.Want to review nomination form?" << endl;
      cout << "3.Want to release election results?" << endl;
      cout << "Write the correct option:";
      cin >> k;
      switch (k)
	{
	case 1:
	  obj1.notice ();
	  break;
	case 2:
	  int o;
	  cout << "Choose the post you want review" << endl;
	  cout << "1.Vice President" << endl;
	  cout << "2.General Secretary" << endl;
	  cout << "3.General Secretary(Cultural)" << endl;
	  cout << "4.General Secretary(Sports)" << endl;
	  cout << "5.General Secretary(Technical)" << endl;
	  cin >> o;
	  switch (o)
	    {
	    case 1:
	      obj1.view_vp ();
	      break;
	    case 2:
	      obj1.view_gs ();
	      break;
	    case 3:
	      obj1.view_gs_cultural ();
	      break;
	    case 4:
	      obj1.view_gs_sports ();
	      break;
	    case 5:
	      obj1.view_gs_technical ();
	      break;
	    }
	    break;
	    case 3:
	    obj1.result();
	    break;

	}
 break;

    case 2:
      int p;
      cout << "1.Want to read notice by dean?" << endl;
      cout << "2.Want to fill nomination form?" << endl;
      cout << "3.Want to withdraw your name?" << endl;
      cout << "4.Want to release Manifesto?" << endl;
      cout << "5.Want to see final candidate list?" << endl;
      cout << "6.Want to see election result?" << endl;
      cout << "Write the correct option:";
      cin >> p;
      switch (p)
	{
	case 1:
	  obj2.view_notice ();
	  break;
	case 2:
	  obj1.nomination ();
	  break;
	case 3:
	  obj1.withdraw_name ();
	  break;
	case 4:
	  obj2.Manifesto();
	  break;
	case 5:
	   int o;
	  cout << "Choose the post you want review" << endl;
	  cout << "1.Vice President" << endl;
	  cout << "2.General Secretary" << endl;
	  cout << "3.General Secretary(Cultural)" << endl;
	  cout << "4.General Secretary(Sports)" << endl;
	  cout << "5.General Secretary(Technical)" << endl;
	  cin >> o;
	  switch (o)
	    {
	    case 1:
	      obj1.view_vp ();
	      break;
	    case 2:
	      obj1.view_gs ();
	      break;
	    case 3:
	      obj1.view_gs_cultural ();
	      break;
	    case 4:
	      obj1.view_gs_sports ();
	      break;
	    case 5:
	      obj1.view_gs_technical ();
	      break;
	    }
	    break;
	  case 6:
    obj1.result();
    break;
      
	    } 
	  
	   break;


    case 3:
      int h;
      cout << "1.Want to vote?" << endl;
      cout << "2.Want to see manifesto" << endl;
      cin >> h;
      switch (h)
	{
	case 1:
	  obj3.vote1 ();
	  break;
	case 2:
	  obj2.view_manifesto();
	  break;
	}
	break;
    }

  return 0;
}
