#include<iostream>
#include<fstream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;

void Heading()
{
		cout << "\n\n\t\t\t\t=======================================================================";
		cout << "\n\t\t\t\t=======================================================================" << endl << endl;

		cout << "\t\t\t\t\t\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM" << endl;

		cout << endl << "\t\t\t\t=======================================================================";
		cout << endl << "\t\t\t\t=======================================================================";
}

class HospitalRooms;			// Forward Declaration
class EmployeeVariables
{
protected:
	int id;
	string Employeename;
	string specialist;
	double salary;
	double balance;
	int fees;
	//Appointment data variable
	int tokenNO;
	string patientName;
	int agePatient;
	string checkUp_Date;
	//Rooms Data varible
	EmployeeVariables()
	{
		balance = 0;
	}
};


class Employee :public EmployeeVariables
{
protected:
	// Data Member Use in File Handling 
	int token;
	string patientN;
	int aPatient;
	string checkUp_D;

	int id_Doctor;
	string Doctorname;
	string special;
	double sal;
	int bal;
	//Fees Function
	void FEES()
	{
		fstream filebal, fileBalance1;
		filebal.open("BalanceHospital.txt", ios::in);
		if (!filebal)
		{
			filebal.open("BalanceHospital.txt", ios::out | ios::app);
			filebal << balance;
			filebal.close();
		}
		fileBalance1.open("BalanceHospital1.txt", ios::out | ios::app);
		filebal >> balance;
		{
			balance += 500;
			fileBalance1 << balance;
			filebal >> balance;
		}
		fileBalance1.close();
		filebal.close();
		remove("BalanceHospital.txt");
		rename("BalanceHospital1.txt", "BalanceHospital.txt");
	}
	
public:

	void addEmployee()
	{
		int c;
		cout << "\n\n\t\t\t\tEnter Doctor ID: ";
		cin >> id;
		cout << "\n\n\t\t\t\tEnter Doctor Name: ";
		cin >> Employeename;
		
		//cin >> specialist;
		const string speciaLIST[8] = { "Eye","Skin","ENT","Dentist","Neurologist","Psychologist","Cardiologist","General" };
		cout << "\n\n\t\t\t\t0) Eye Specialist" << endl;
		cout << "\n\n\t\t\t\t1) Skin Specialist" << endl;
		cout << "\n\n\t\t\t\t2) ENT Specialist" << endl;
		cout << "\n\n\t\t\t\t3) Dentist " << endl;
		cout << "\n\n\t\t\t\t4) Neurologist" << endl;
		cout << "\n\n\t\t\t\t5) Psychologist" << endl;
		cout << "\n\n\t\t\t\t6) Cardiologist" << endl;
		cout << "\n\n\t\t\t\t7) General Specialist" << endl << endl;
		cout << "\n\n\t\t\t\tEnter Specialization: ";
		cin >> c;
		int size = 8;

		for (int i = 0; i < size; i++)
		{
			if (c == i)
			{
				specialist = speciaLIST[i];
			}
		}
		cout << "\n\n\t\t\t\tEnter Doctor Salary: ";
		cin >> salary;
		fstream file;
		//file.open("EMS", ios::in);
		file.open("EMS.txt", ios::app | ios::out);
		file << id << " " << Employeename << " " << specialist << " " << salary << endl;
		file.close();
		cout << "\n\n\t\t\t\tDoctor Added Successfully!" << endl << endl;
	}

	//search Employee
	void searchEmployee(int searchID)
	{
		fstream file;
		file.open("EMS.txt", ios::in);
		if (!file)
		{
			cout << "\n\n\t\t\t\tNo Data to Search!" << endl << endl;
		}
		else
		{
			file >> id_Doctor >> Doctorname >> special >> sal;
			while (!file.eof())
			{
				if (id_Doctor == searchID)
				{
					cout << endl;
					cout << "\n\n\t\t\t\tDoctor ID: " << id_Doctor << endl;
					cout << "\n\n\t\t\t\tDocotr Name: " << Doctorname << endl;
					cout << "\n\n\t\t\t\tDoctor Specialization: " << special << endl;
					cout << "\n\n\t\t\t\tDoctor Salary: " << sal << endl;
					cout << endl << endl << endl;
				}
				file >> id_Doctor >> Doctorname >> special >> sal;
			}
			file.close();
		}
	}

	void deleteEmployee(int iD)
	{
		fstream file, file1;
		file.open("EMS.txt", ios::in);
		if (!file)
		{
			cout << "No Data to Delete Yet" << endl;
		}
		else
		{
			int found = 0;
			file1.open("EMS1.txt", ios::app | ios::out);
			file >> id >> Employeename >> specialist >> salary;
			while (!file.eof())
			{
				if (id == iD)
				{
					found++;
					cout << "\n\n\t\t\t\tData Deleted Successfully" << endl << endl;
				}
				else
				{
					file1 << id << " " << Employeename << " " << specialist << " " << salary << endl;
				}
				file >> id >> Employeename >> specialist >> salary;
			}
			file.close();
			file1.close();
			remove("EMS.txt");
			rename("EMS1.txt", "EMS.txt");
			if (found == 0)
			{
				cout << "Data Not Found......" << endl;
			}
		}

	}

	void showEmployees()
	{
		fstream file;
		file.open("EMS.txt", ios::in);
		if (!file)
		{
			cout << "No Doctor Added Yet, Please Add Doctors First!" << endl;
		}
		else
		{
			file >> id >> Employeename >> specialist >> salary;
			while (!file.eof())
			{
				cout << endl;
				cout << "\n\n\t\t\t\tDoctor ID: " << id << endl;
				cout << "\n\n\t\t\t\tDocotr Name: " << Employeename << endl;
				cout << "\n\n\t\t\t\tDoctor Specialization: " << specialist << endl;
				cout << "\n\n\t\t\t\tDoctor Salary: " << salary << endl;
				cout << endl;
				file >> id >> Employeename >> specialist >> salary;
			}
		}
		file.close();
	}

	//Appoint
	void AppointmentPatientData()
	{
		p:
		//int fees = 500;
		cout << "\n\n\t\t\t\tEnter Patient Name: ";
		cin.ignore();
		getline (cin, patientName);
		cout << "\n\n\t\t\t\tEnter Patient Age: ";
		cin >> agePatient;
		cout << "\n\n\t\t\t\tEnter Patient Checkup Date: ";
		cin >> checkUp_Date;
		cout << "\n\n\t\t\t\tEnter Token Number: ";
		cin >> tokenNO;
		fstream file, fileBalance, fileBalance1;//FileBalance create file store Balance
		file.open("Appointment.txt", ios::in);
		if (!file)
		{
			file.open("Appointment.txt", ios::out | ios::app);
			file << tokenNO << " " << patientName << " " << agePatient << " " << checkUp_Date << endl;
			//FileBalance create fle store Balance
			FEES();
			file.close();
		}
		else
		{
			file >> token >> patientN >> aPatient >> checkUp_D;
			while (!file.eof())
			{
				if (tokenNO == token)
				{
					cout << "\n\t\t\t\tYour Token Number Already Exist.... " << endl;
					goto p;
				}
				file >> token >> patientN >> aPatient >> checkUp_D;
			}
			file.close();
			file.open("Appointment.txt", ios::out | ios::app);
			file << tokenNO << " " << patientName << " " << agePatient << " " << checkUp_Date << endl;
			FEES();
			file.close();

		}
		cout << "\n\n\n\t\t\t\t Your Token Number is " << tokenNO << endl;

	}
	void Appointment()
	{
		int c;
		string storeSP;
		const int size = 8;
		string speciaLIST[size] = { "Eye","Skin","ENT","Dentist","Neurologist","Psychologist","Cardiologist","General" };
		cout << "\n\n\t\t\t\t0) Eye Specialist" << endl;
		cout << "\n\n\t\t\t\t1) Skin Specialist" << endl;
		cout << "\n\n\t\t\t\t2) ENT Specialist" << endl;
		cout << "\n\n\t\t\t\t3) Dentist " << endl;
		cout << "\n\n\t\t\t\t4) Neurologist" << endl;
		cout << "\n\n\t\t\t\t5) Psychologist" << endl;
		cout << "\n\n\t\t\t\t6) Cardiologist" << endl;
		cout << "\n\n\t\t\t\t7) General Doctor" << endl;
		cout << "\n\n\t\t\t\tSelect Specialist: ";
		cin >> c;

		for (int i = 0; i < size; i++)
		{
			if (c == i)
			{
				storeSP = speciaLIST[i];
				break;
			}
		}
		string b;
		fstream file;
		int found = 0;
		file.open("EMS.txt", ios::in);
		int a = 0;
		if (!file)
		{
			cout << "\n\n\t\t\t\tDoctor Not Availble" << endl;
		}
		else
		{
			file >> id_Doctor >> Doctorname >> special >> sal;
			while (!file.eof())
			{
				if (special == storeSP)
				{
					cout << "\n\n\t\t\t\t" << special << " Specialist " << Doctorname << endl;
					AppointmentPatientData();
				}
			
				file >> id_Doctor >> Doctorname >> special >> sal;
			}
	
			file.close();
		}
	}
	//Appoint

	void checkAppointments()
	{
		int i = 0;
		fstream file;
		file.open("Appointment.txt", ios::in);
		if (!file)
		{
			cout << "\n\n\t\t\t\tNo Appointments Made Yet!" << endl;
		}
		else
		{
			cout << endl << endl << endl << endl;
			cout << "\t\t\t\t" << left << setw(10) << "NO." << setw(13) << "Token No" << setw(17) << "Patient Name" << setw(9) << "Age" << setw(16) << "CheckUp Date" << endl;
			file >> token >> patientN >> aPatient >> checkUp_D;
			cout << endl;
			while (!file.eof())
			{
				cout << "\t\t\t\t" << left << setw(10) << ++i << setw(13) << token << setw(17) << patientN << setw(9) << aPatient << setw(16) << checkUp_D << endl;
				file >> token >> patientN >> aPatient >> checkUp_D;
				cout << endl << endl;
			}
		}
		file.close();
	}
};


//Rooms
class HospitalRooms :public EmployeeVariables
{
private:
	int token;
	string patientN;
	int aPatient;
	string checkUp_D;

	int id_Doctor;
	string Doctorname;
	string special;
	double sal;
	int bal;
	//fees
	void FEES()
	{
		fstream filebal, fileBalance1;
		filebal.open("BalanceHospital.txt", ios::in);
		if (!filebal)
		{
			filebal.open("BalanceHospital.txt", ios::out | ios::app);
			filebal << balance;
			filebal.close();
		}
		fileBalance1.open("BalanceHospital1.txt", ios::out | ios::app);
		filebal >> balance;
		{
			balance += 1500;
			fileBalance1 << balance;
			filebal >> balance;
		}
		fileBalance1.close();
		filebal.close();
		remove("BalanceHospital.txt");
		rename("BalanceHospital1.txt", "BalanceHospital.txt");
	}
	
public:
	HospitalRooms()
	{

	}
	//Check Balance in Hospital
	void checkBalance()
	{
		fstream file;
		file.open("BalanceHospital.txt", ios::in);
		file >> balance;
		{
			file >> balance;
			cout << "\n\n\t\t\t\tTotal Account Balance is " << balance << endl;
		}
		file.close();
	}

	//Function chackup Option 2
	void OptionNO2(int tokNO)
	{
		fstream file, file1;
		file.open("Appointment.txt", ios::in);
		if (!file)
		{
			cout << "\n\n\t\t\t\tFile is Empty<" << endl;
		}
		else
		{
			int found = 0;
			file1.open("Appointment1.txt", ios::app | ios::out);
			file >> tokenNO >> patientName >> agePatient >> checkUp_Date;
			while (!file.eof())
			{
				if (tokenNO == tokNO)
				{
					found++;
					cout << "\n\n\t\t\t\tThanks For Coming......." << endl;
					cout << endl << endl;
				}
				else
				{
					file1 << tokenNO << " " << patientName << " " << agePatient << " " << checkUp_Date << endl;
				}
				file >> tokenNO >> patientName >> agePatient >> checkUp_Date;
			}
			file.close();
			file1.close();
			remove("Appointment.txt");
			rename("Appointment1.txt", "Appointment.txt");
			if (found == 0)
			{
				cout << "\n\t\t\t\tData Not Found......" << endl;
			}
		}
	}
	void Checkup()
	{
		int tokNO;
		cout << "\n\n\t\t\t\tEnter Token No: ";
		cin >> tokNO;
		int admit;
		cout << "\n\n\t\t\t\tAdmit Patient? " << endl;
		cout << "\n\n\t\t\t\t 1. YES (FEES Room 1500)" << endl;
		cout << "\n\n\t\t\t\t 2. No" << endl;
		cout << "\n\n\t\t\t\tSelect 1 || Select 2 : ";
		cin >> admit;
		HospitalRooms a;
		if (admit == 1)
		{
			a.RoomsInHospital(tokNO);
		}
		if (admit == 2)
		{
			OptionNO2(tokNO);
		}
	}

	//Rooms In Hospital
	void RoomsInHospital(int tokenNumber)
	{
		int c;
		int roomsHospital;
		const int size = 10;
		int rooms[size] = { 1,2,3,4,5,6,7,8,9,10 };
		p:
		cout << "\n\n\t\t\t\t0) Room No: 1" << endl;
		cout << "\n\n\t\t\t\t1) Room No: 2" << endl;
		cout << "\n\n\t\t\t\t2) Room No: 3" << endl;
		cout << "\n\n\t\t\t\t3) Room No: 4 " << endl;
		cout << "\n\n\t\t\t\t4) Room No: 5" << endl;
		cout << "\n\n\t\t\t\t5) Room No: 6" << endl;
		cout << "\n\n\t\t\t\t6) Room No: 7" << endl;
		cout << "\n\n\t\t\t\t7) Room No: 8" << endl;
		cout << "\n\n\t\t\t\t8) Room No: 9" << endl;
		cout << "\n\n\t\t\t\t9) Room No: 10" << endl << endl;
		cout << "\n\n\t\t\t\tSelect Room: ";
		cin >> c;
		for (int i = 0; i < size; i++)
		{
			if (c == i)
			{
				roomsHospital = rooms[i];
				break;
			}
		}


		//read file 
		int r;
		fstream file1, file, fileAppointment;
		int found = 0;

		//store patient datail in room file
		fileAppointment.open("Appointment.txt", ios::in);
		if (!fileAppointment)
		{
			cout << "\n\n\t\t\t\tfile is Empty" << endl;
		}
		else
		{
			file.open("Room.txt", ios::out | ios::app);
			fileAppointment >> token >> patientN >> aPatient >> checkUp_D;
			while (!fileAppointment.eof())
			{
				if (token == tokenNumber)
				{
					file << token << " " << patientN << " " << aPatient << " " << checkUp_D << " " << roomsHospital << endl;
					cout << "\n\n\t\t\t\tYour Room Number is " << roomsHospital << endl;
					FEES();
					system("pause");
				}
				fileAppointment >> token >> patientN >> aPatient >> checkUp_D;
			}
		}
		fileAppointment.close();
		file.close();
	}
	//Room Chack BOOKED
	void Check_Rooms()
	{
		int a = 0;
		fstream f;
		f.open("Room.txt", ios::in);
		if (!f)
		{
			cout << "\n\n\n\n\t\t\t\tRooms are Empty, No Patients are Admitted" << endl << endl << endl;
		}
		else
		{
			int room;
			cout << endl << endl;
			cout << "\t\t\t\t" << left << setw(7) << "NO." << setw(13) << "Token No" << setw(17) << "Patient Name" << setw(9) << "Age" << setw(16) << "CheckUp Date" << setw(16) << "Room NO" << endl;
			f >> token >> patientN >> aPatient >> checkUp_D >> room;
			cout << endl;
			while (!f.eof())
			{
				cout << "\t\t\t\t" << left << setw(7) << ++a << setw(13) << token << setw(17) << patientN << setw(9) << aPatient << setw(16) << checkUp_D << setw(16) << room << endl;
				f >> token >> patientN >> aPatient >> checkUp_D >> room;
				cout << endl << endl;
			}
		}
		f.close();

	}

	///DisCharge

	void dischargePatient(int t)
	{
		int found = 0;
		fstream file, file1;
		file.open("Room.txt", ios::in);
		if (!file)
		{
			cout << "\n\n\t\t\t\tRooms are Already Empty" << endl;
		}
		else
		{
			int room;
			file1.open("Room1.txt", ios::out | ios::in);
			file >> token >> patientN >> aPatient >> checkUp_D >> room;

			while (!file.eof())
			{
				if (token == t)
				{
					found++;
					cout << "\n\n\t\t\t\tPatient Has Been Discharged From Hospital..." << endl << endl;
				}
				else
				{
					file1 << token << " " << patientN << " " << aPatient << " " << checkUp_D << " " << room << endl;;
				}
				file >> token >> patientN >> aPatient >> checkUp_D >> room;
			}
		}

		file1.close();
		file.close();
		remove("Room.txt");
		rename("Room1.txt", "Room.txt");
		if (found == 0)
		{
			cout << "\n\t\t\t\tToken Number Not Found" << endl;
		}
		OptionNO2(t);
	}
};


int main()
{
	Employee *e = new Employee();
	HospitalRooms *h = new HospitalRooms();
	int choice;
	p:
	while (true)
	{
		system("cls");
		Heading();
	
		cout << "\n\n\t\t\t\t1) Add Doctor" ;
		cout << "\n\n\t\t\t\t2) Search Doctor";
		cout << "\n\n\t\t\t\t3) Delete Doctor" ;
		cout << "\n\n\t\t\t\t4) Show Doctors" ;
		cout << "\n\n\t\t\t\t5) Book Appointment" ;
		cout << "\n\n\t\t\t\t6) Check Appointments";
		cout << "\n\n\t\t\t\t7) Checkup" ;
		cout << "\n\n\t\t\t\t8) Balance Check" ;
		cout << "\n\n\t\t\t\t9) Discharge Patient";
		cout << "\n\n\t\t\t\t10) Check Rooms";
		cout << "\n\n\t\t\t\t11) Exit" << endl << endl;
		cout << "\n\n\t\t\t\tEnter your choice: ";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
			{
				system("cls");
				Heading();
				e->addEmployee();
				system("pause");
				break;
			}
			
			case 2:
			{
				system("cls");
				Heading();
				int id;
				cout << "\n\n\t\t\t\tEnter ID: ";
				cin >> id;
				e->searchEmployee(id);
				system("pause");
				break;
			}
			
			case 3:
			{
				system("cls");
				Heading();
				int id;
				cout << "\n\n\t\t\t\tEnter ID: ";
				cin >> id;
				e->deleteEmployee(id);
				system("pause");
				break;
			}
			
			case 4:
			{
				system("cls");
				Heading();
				e->showEmployees();
				system("pause");
				break;
			}
			
			case 5:
			{
				system("cls");
				Heading();
				e->Appointment();
				goto p;
				system("pause");
				break;
			}
			
			case 6:
			{
				system("cls");
				Heading();
				e->checkAppointments();
				system("pause");
				break;
			}
			
			case 7:
			{
				system("cls");
				Heading();
				h->Checkup();
				goto p;
				system("pause");
				break;
			}
			
			case 8:
			{
				system("cls");
				Heading();
				h->checkBalance();
				system("pause");
				break;
			}
			
			case 9:
			{
				system("cls");
				Heading();
				int t;
				cout << "\n\n\t\t\t\tEnter Token No: ";
				cin >> t;
				h->dischargePatient(t);
				system("pause");
				break;
			}
			
			case 10:
			{
				system("cls");
				Heading();
				h->Check_Rooms();
				system("pause");
				break;
			}
			
			case 11:
			{
				cout << "\n\n\t\t\t\tThanks for Using Our Program..." << endl;
				cout << "\n\n\t\t\t\tExiting..." << endl;
				exit(0);
				break;
			}

			default:
			{
				cout << "\n\n\t\t\t\tPlease Enter Valid Option: ";
				break;
			}
		}
	}
}
