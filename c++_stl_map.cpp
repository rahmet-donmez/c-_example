#include<iostream>
#include<map>

using namespace std;

template <typename T>
void print(T& x){
	typename T::iterator it = x.begin();
	
	if(x.empty()){
		cout<<"no element";
	}
	else{
		cout<<"Elements"<<endl<<"................."<<endl;
		while(it!=x.end()){
			cout<<it->first<<" "<<it->second<<" "<<endl;
			it++;
		}
	}
	
	cout<<endl;
}

int main(){
	cout<<endl<<"	m1	"<<endl;
	map <string,int> m1;
	
	cout<<"is it empty? : "<<m1.empty()<<endl;//!bo� olma durumunu kontrol eder
	

	pair<string,int> p1("konya",42);
	pair<string,int> p2("istanbul",34);
	pair<string,int> p3("ankara",06);
	pair<string,int> p4("izmir",35);
	pair<string,int> p5("bolu",14);
	pair<string,int> p6("antalya",07);
	
	//!alfabeye g�re s�ralanarak ekleme yap�l�r
	m1.insert(p1);//eleman ekleme
	print(m1);
	cout<<"is it empty? : "<<m1.empty()<<endl;
	
	
	//!bir eleman bir kez eklenir. bu y�zden p1 in tekrar eklenmesi hi�bir �eyi de�i�tirmez. boyut ayn� kal�r
	print(m1);
	cout<<"size: "<<m1.size()<<endl;
	m1.insert(p1);
	print(m1);
	cout<<"size: "<<m1.size()<<endl;//!boyutu verir
	
	cout<<"konya:"<<m1["konya"]<<endl;//!konya ya kar��l�k gelen de�eri verir
	
	m1.insert(p2);
	m1.insert(p3);
	print(m1);
		
	
	
	
	m1.erase(m1.begin());//!konum vererek eleman silme i�lemini ger�ekle�tirir. verilen konumdan itibaren t�m elemanlar� siler
	print(m1);
	m1.erase("konya");//!de�ere kar��l�k gelen adresteki veriyi siler
	print(m1);
	m1.erase(m1.begin(),m1.end()); //!aral�k vererek eleman silme
	print(m1);
	m1.insert(p1);
	m1.insert(p3);
	m1.insert(p4);
	print(m1);
	m1.erase(m1.begin(),m1.lower_bound("izmir"));//!ba�lang�� ve biti� konumu vererek veri siler. lower_bound=>izmir verisinin bulundu�u alt s�n�r� verir
	print(m1);
	
	m1.insert(p1);
	m1.insert(p2);
	m1.insert(p3);
	m1.insert(p4);
	m1.insert(p5);
	m1.insert(p6);
	print(m1);
	
	cout<<endl<<"m2 "<<endl;
	map <string,int> m2(m1);
	print(m2);
	m2.clear();//!verilen de�i�kendeki t�m verileri temizler
	print(m2);
	
	cout<<endl<<"m3 "<<endl;
	//!ankara verisinin bulundu�u adresten istanbul verisinin bulundu�u adrese kadar olan verileri m3 e ekler
	map <string,int> m3(m1.find("ankara"),m1.find("istanbul"));
	print(m3);
	
	//!m1 ile m3 �n i�erikleri kar��l�kl� de�i�tirilir. m1 in elemanlar� m3 e, m3 �n elemanlar� m1 e kaydedilir
	cout<<endl<<"swap m1-m3"<<endl;
	cout<<"before m1 ";
	print(m1);
	cout<<"before m3 ";
	print(m3);
	
	m1.swap(m3);
	
	cout<<"after m1 ";
	print(m1);
	cout<<"after m3 ";
	print(m3);
	
	
	/**********************************
	******* MULT� MAP
	****************************************/
	
	cout<<endl<<"		MULTIMAP		"<<endl;
	cout<<endl<<"m4 ";
	multimap <string,int> m4;

	m4.insert(p4);
	m4.insert(p2);
	m4.insert(p4);//!bir eleman birden fazla kez eklenebilir
	m4.insert(p1);
	m4.insert(p4);
	m4.insert(p3);

	print(m4);
	cout<<"number of izmir: "<<m4.count("izmir")<<endl;//!m4 de bulunan izmir verilerinin say�s�n� verir
	
	/*!erase fonksiyonu ile verilen aral�ktaki verileri siler. bu i�lem sonucunda b�t�n izmir verileri silinmi� olur.
	lower_bound ile izmir verisinin bulundu�u alt s�n�r, upper_bound ile izmir verisinin bulundu�u �st s�n�r elde edilir.
 	*/
	m4.erase(m4.lower_bound("izmir"),m4.upper_bound("izmir"));
	print(m4);
	cout<<"number of izmir: "<<m4.count("izmir")<<endl;
	
	
	
	/*! yukar�daki i�lem �nce aral�k elde edilerek de yap�labilir. equal_range ile aral�k elde edilir ve pair de�i�kenine aktar�l�r. 
	sonras�nda erase fonksiyonuna pair de�i�kenin verileri aktar�larak silme i�lemi ger�ekle�tirilir.
	*/
	m4.insert(p4);
	m4.insert(p4);
	m4.insert(p4);
	print(m4);
	pair<multimap<string,int>::iterator,multimap<string,int>::iterator> pair=m4.equal_range("izmir");
	m4.erase(pair.first,pair.second);
	print(m4);
	

		
}
