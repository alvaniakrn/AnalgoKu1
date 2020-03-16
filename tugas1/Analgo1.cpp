/*
Alvina Vania Kirana
140810180010
Praktikum Analisis Algoritma
Tugas 1
*/
#include<iostream>
using namespace std;

typedef int prefer[5];

	struct person{
	     string name;
	     int match;
	     int p[5];
	};

person setPerson(string name, prefer prefers);
void stableMatching(person (&man)[5], person (&woman)[5]);

int main(){
    person man[5], woman[5];
    prefer prefers;

        //name of man in here
		prefers[0] = 1; prefers[1] = 0; prefers[2] = 3; prefers[3] = 4; prefers[4] = 2;
		man[0] = setPerson("Victor",prefers);
		prefers[0] = 3; prefers[1] = 1; prefers[2] = 0; prefers[3] = 2; prefers[4] = 4;
		man[1] = setPerson("Wyatt",prefers);
		prefers[0] = 1; prefers[1] = 4; prefers[2] = 2; prefers[3] = 3; prefers[4] = 0;
		man[2] = setPerson("Xavier",prefers);
		prefers[0] = 0; prefers[1] = 3; prefers[2] = 2; prefers[3] = 1; prefers[4] = 4;
		man[3] = setPerson("Yancey",prefers);
		prefers[0] = 1; prefers[1] = 3; prefers[2] = 0; prefers[3] = 4; prefers[4] = 2;
		man[4] = setPerson("Zeus",prefers);

		//woman
		prefers[0] = 4; prefers[1] = 0; prefers[2] = 1; prefers[3] = 3; prefers[4] = 2;
		woman[0] = setPerson("Amy",prefers);
		prefers[0] = 2; prefers[1] = 1; prefers[2] = 3; prefers[3] = 0; prefers[4] = 4;
		woman[1] = setPerson("Bertha",prefers);
		prefers[0] = 1; prefers[1] = 2; prefers[2] = 3; prefers[3] = 4; prefers[4] = 0;
		woman[2] = setPerson("Clare",prefers);
		prefers[0] = 0; prefers[1] = 4; prefers[2] = 3; prefers[3] = 2; prefers[4] = 1;
		woman[3] = setPerson("Diane",prefers);
		prefers[0] = 3; prefers[1] = 1; prefers[2] = 4; prefers[3] = 2; prefers[4] = 0;
		woman[4] = setPerson("Erika",prefers);

	     stableMatching(man,woman);

	     cout << "Stable Matching :" << endl;
	     cout << "Man \t Woman\t" << endl;
	     for(int i = 0; i < 5; i++){
	          cout << "" << man[i].name << "\tx " << woman[man[i].match].name << "\t" << endl;
	     }
	}

person setPerson(string name, prefer prefers){
	     person pers;
	     pers.name = name;
	     pers.match = -1;
	     for(int i = 0; i < 5;i++){
	          pers.p[i] = prefers[i];
	     }
	     return pers;
	}

void stableMatching(person man[5], person woman[5]){
	     bool free = true;
	     int i=0, j=0, prefSek,prefSuk;
	     while(free){
	          if(woman[man[i].p[j]].match = -1){
	               man[i].match = man[i].p[j];
	               woman[man[i].p[j]].match = i;
	          }else{
				int k = 0;
				prefSek = -1; prefSuk = -1;
				while(prefSek == -1 || prefSuk == -1){
					if(i == woman[man[i].p[j]].p[k]){
						prefSuk = k;
					}
					if(woman[man[i].p[j]].match == woman[man[i].p[j]].p[k]){
						prefSek = k;
					}
					k++;
				}
				if(prefSuk<prefSek){
					man[woman[man[i].p[j]].match].match = -1;
					man[i].match = man[i].p[j];
					woman[man[i].p[j]].match = i;
				}else{
					j++;
					continue;
				}
			}
			free = false;
			j=0;
			for(int l = 0; l < 5; l++){
				if(man[l].match == -1){
					i = l;
					free = true;
					break;
				}
			}
	     }
	}


