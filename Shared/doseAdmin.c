#include "doseAdmin.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define TABLE_SIZE 113
#define MEASUREMENT_SIZE 10



typedef struct doseData 
{
	float doseAmount;
	time_t examDate;
} doseData;

typedef struct patientData
{
	float measurements[MEASUREMENT_SIZE];
	doseData dose;
}patientData;

typedef struct patient
{
	char nameP[MAX_PATIENTNAME_SIZE]; /*KEY*/
	patientData pData; /*VALUE*/
	int taken;
	/*struct patient *next; /*POINTER TO THE NEXT ITEM IN THE LIST FOR LATER*/
} patient;

patient hashtable[TABLE_SIZE];



static uint8_t hashFunction(char patientName[MAX_PATIENTNAME_SIZE])
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
	return;
	
}
 
void RemoveAllDataFromHashTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashtable[i].taken == 1)
		{
			for (int j = 0; j < MEASUREMENT_SIZE; j++)
			{
				hashtable[i].pData.measurements[j] = 0;
			}
			hashtable[i].pData.dose.doseAmount = 0;
			hashtable[i].pData.dose.examDate = 0;
		}
		
	}
		
}
 
int8_t AddPatient(char patientName[MAX_PATIENTNAME_SIZE])
{
	int slot = hashFunction(patientName);
	
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashtable[slot].taken == 0)
		{
			hashtable[slot].taken = 1;
			strcpy(hashtable[slot].nameP, patientName);
		}
		slot = (slot + 1) % TABLE_SIZE;
		
		
	}
	
	
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
	if (strlen(patientName) > MAX_PATIENTNAME_SIZE)
	{
		return -2;
	}
	
	int key = hashFunction(patientName);

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashtable[key].taken == 1)
		{
			hashtable[key].taken = 0;
			hashtable[key].nameP[0] = '\0';
			hashtable[key].pData.dose.doseAmount = 0;
			hashtable[key].pData.dose.examDate = 0;

			for (int j = 0; j < MEASUREMENT_SIZE; j++)
			{
				hashtable[key].pData.measurements[j] = 0;
			}
			return 0;
			
		}
		

		key = (key + 1) % TABLE_SIZE;
	}
	return -1;
	
}
 
int8_t IsPatientPresent(char patientName[MAX_PATIENTNAME_SIZE])
{
	if (strlen(patientName) > MAX_PATIENTNAME_SIZE)
	{
		return -2;
	}
	
	int key = hashFunction(patientName);
	
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashtable[key].taken == 1)
		{
			return 0;
		}
		key = (key + 1) % TABLE_SIZE;
		
	}
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
