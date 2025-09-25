#include "doseAdmin.h"
#include <string.h>
#include <stdbool.h>
#define TABLE_SIZE 113
#define MEASUREMENT_SIZE 10

int hashTable[11][TABLE_SIZE];

typedef struct {
	char nameP[MAX_PATIENTNAME_SIZE];
	float measurements[MEASUREMENT_SIZE];
	bool isPresent;
} patient;


static int hashFunction(char patientName[MAX_PATIENTNAME_SIZE])
{
	int sum = 0;
	int hash = 0;
	int counter = 0;
	int len = strlen(patientName);
	int len2 = 0;

	for (int i = 0; i < len; i++)
	{
		if (patientName[i] != ' ')
		{
			char p = patientName[i];
			int ascii = (int) p;
			counter += 1;
			sum = sum + ascii;
		}
		
		
	}

	hash = (sum * counter) / TABLE_SIZE;
	return hash;
	
	
}


void CreateHashTable()
{
	
}
 
void RemoveAllDataFromHashTable()
{
	return;
}
 
int8_t AddPatient(char patientName[MAX_PATIENTNAME_SIZE])
{
	return;
}
 
/*int8_t AddPatientDose(char patientName[MAX_PATIENTNAME_SIZE], Date* date, uint16_t dose)
{
	return -1;
}
 
int8_t PatientDoseInPeriod(char patientName[MAX_PATIENTNAME_SIZE], Date* startDate, Date* endDate, uint32_t* totalDose)
{
	return -1;
}*/
 
int8_t RemovePatient(char patientName[MAX_PATIENTNAME_SIZE])
{
	return -1;
}
 
int8_t IsPatientPresent(char patientName[MAX_PATIENTNAME_SIZE])
{
	return -1;
}

/*int8_t GetNumberOfMeasurements(char patientName[MAX_PATIENTNAME_SIZE], size_t * nrOfMeasurements)
{
	return -1;
}

void GetHashPerformance(size_t *totalNumberOfPatients, double *averageNumberOfPatients, double *standardDeviation)
{
	return;
}
				
int8_t WriteToFile(char filePath[MAX_FILEPATH_LEGTH])
{
	return -1;
}

int8_t ReadFromFile(char filePath[MAX_FILEPATH_LEGTH])
{
	return -1;
}*/
