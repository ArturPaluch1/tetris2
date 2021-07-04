#include <iostream>
#include <stdio.h>
#include <time.h>  // wymagana do czasu
#include <conio.h>  //wymagana do getch
#include <cstdlib> //losowosc
#include<Windows.h>  //bibl do bufora
#include "intro.h"
#include "funkcje.hpp"

using namespace std;
void wyswietl_intro(int szybko_1)
{
	HANDLE hOut; //uchwyt dla kolorów
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int ile = 0;
	//bia³e elementy
	int tabelaklockow[220] = { 64,65,66,67,68,69,70,71,72,73,76,77,78,79,80,81,84,85,86,87,88,89,90,91,92,93,96,97,98,99,106,107,110,111,112,113,114	,115	,124	,125	,126	,127	,128	,129	,130	,131	,132	,133	,136	,137	,138	,139	,140	,141	,144	,145	,146	,147	,148	,149	,150	,151	,152	,153	,156	,157	,158	,159	,160	,161	,166	,167	,170	,171	,172	,173	,174	,175	,188	,189	,196	,197	,	208	,	209	,	216	,217	,220	,221	,230	,231	,248	,249	,256	,257	,268	,269	,276	,277	,280	,281	,290	,291	,308	,309	,316	,317	,318	,319	,320	,321	,328	,329	,336	,337	,338	,339	,340	,341	,346	,347	,350	,351	,352	,353	,354	,355	,368	,369	,376	,377	,378	,379	,380	,381	,388	,389	,396	,397	,398	,399	,406	,407	,410	,411	,412	,413	,414	,415	,428	,429	,436	,437	,448	,449	,456	,457	,460	,461	,466	,467	,474	,475	,488	,489	,496	,497	,508	,509	,516	,517	,520	,521	,526	,527	,534	,535	,548	,549	,556	,557	,558	,559	,560	,561	,568	,569	,576	,577	,580	,581	,586	,587	,590	,591	,592	,593	,594	,595	,608	,609	,616	,	617	,618	,619	,620	,621	,628	,629	,636	,637	,640	,	641	,	646	,647	,650	,651	,652	,653	,654	,	655};
	//szare elementy
	int tabelaklockow2[130] = { 74,82,94	,100	,108	,116	,134	,142	,154	,162	,168	,176	,184	,185	,186	,187	,190	,191	,192	,193	,194	,198	,199	,200	,201	,202	,204	,205	,206	,207	,210	,211	,212	,213	,214	,218	,219	,222	,226	,227	,228	,232	,233	,234	,235	,236	,250	,258	,270	,282	,292	,310	,322	,330	,342	,348	,356	,370	,382	,390	,400	,401	,408	,416	,430	,438	,439	,440	,441	,442	,450	,458	,459	,462	,468	,470	,471	,472	,473	,476	,490	,498	,510	,518	,522	,528	,536	,550	,562	,570	,578	,582	,588	,596	,610	,622	,630	,638	,642	,648	,656	,668	,669	,670	,676	,677	,678	,679	,680	,681	,682	,688	,689	,690	,696	,697	,698	,700	,701	,702	,706	,707	,708	,710	,711	,712	,713	,714	,715	,716};
	
	int i = 0, koniec = 0, j = 0, k = 0, jak_szybko;
	char c = 219, d =176; //zmienne kszta³tu znaku
	if (szybko_1 == 0)
		jak_szybko = 5;
	else jak_szybko = 0;
	for (i = 0; i < 779; i++)
	{
		ile = czekaj(jak_szybko, ile); //wywo³anie funkcji czekania. Jeœli jak_szybko==0 wyœwietla od razu. Jeœli ==1 wyœwietla "animacjê"
		if (ile == 1) 
		{
			ile = 0; //zeruje licznik
			{
				if (i == koniec + 59)//jeœli dojdzie do krawêdzi  
				{
					cout << endl; //przejdŸ do nowej linii
					koniec = koniec + 60; 
				}
				else
				{
					if (i == tabelaklockow[j]) //jeœli i zawiera siê w tabelaklockow
					{
						cout << c; //wyœwietla bia³y prostok¹t
						j++;//przesuwa indeks na nastêpny
					}
					else
					{
						if (i == tabelaklockow2[k])
						{
							cout << d;//wyœwietla szary prostok¹t
							k++; //przesuwa indeks na nastêpny	
						}
						else//jeœli indeksu i nie ma w tablicach wyœwietl spacjê
						cout << ' ';
					}
				}
			}
		}
	}
	

}
