#include<iostream>
#include<set>
#include<iterator>


using namespace std;

template <typename T>
void print(T &x){
	typename T::iterator it=x.begin();
	if(x.empty()){
		cout<<"no element"<<endl;
	}
	else{
		cout<<"elements=> ";
		while(it!=x.end()){
			cout<<*it<<" ";
			it++;
		}
		cout<<endl;
	}
	
		
}


int main(){
	cout<<"===s1==="<<endl;
	set <int> s1;
	cout<<"is it empty?: "<<s1.empty()<<endl;//! boþ olma durumunu kontrol eder
	//! veri ekleme iþlemi
	s1.insert(1);
	s1.insert(5);
	s1.insert(2);
	s1.insert(9);
	s1.insert(8);
	s1.insert(3);
	cout<<"is it empty?: "<<s1.empty()<<endl;
	
	
	//! bir eleman sadece bir kez eklenebilir. burada yapýlan iþlemde 2 kez 9 elemaný eklendiði halde 9larýn sayýsý 1 olarak elde edilir
	print(s1);
	s1.insert(9);
	print(s1);
	cout<<"hoe many 9 are there? : "<<s1.count(9)<<endl;//! count fonksiyonu 9 larýn sayýsýný verir
	
	
	cout<<"first element:"<<*s1.begin()<<endl;//! baþlangýç adresindeki veriyi ulaþmamýzý saðlar
	cout<<"last element:"<<*s1.end()<<endl;	//! sondaki elemaný verir
	cout<<"size"<<s1.size()<<endl;//! boyutu verir
	
	

	print(s1);
	s1.erase(s1.begin(),s1.end());//! verilen aralýktaki verileri siler
	print(s1);
	
	s1.insert(1);
	s1.insert(2);
	s1.insert(7);
	s1.insert(8);
	s1.insert(6);
	s1.insert(3);
	s1.insert(5);
	print(s1);
	
	s1.erase(s1.find(2),s1.find(6));//! find fonksiyonu parametre olarak verilen elemanýn bulunduðu adresi verir
	print(s1);
	
	s1.insert(2);
	s1.insert(3);
	s1.insert(5);
	print(s1);

	cout<<endl<<"===s2==="<<endl;
	set <int> s2(s1);
	print(s2);
	s2.clear();
	print(s2);
	
	cout<<endl<<"===s3==="<<endl;
	set <int> s3(s1.lower_bound(3),s1.upper_bound(8));
	print(s3);


	cout<<endl<<"swap s1-s3"<<endl;
	cout<<"before s1 ";
	print(s1);
	cout<<"before s3 ";
	print(s3);
	
	
	s1.swap(s3);
	
	cout<<"after s1 ";
	print(s1);
	cout<<"after s3 ";
	print(s3);
	
	
	int array[]={1,5,4,6,9,3};
	
	set <int> s4(array,array+5);//! dizi ile deðer atamasý yapýlabilir
	cout<<endl<<"===s4==="<<endl;
	print(s4);
	

	
	
	
	//! MULTI SET
	//! multiset bir eleman bir çok kez eklenebilir
	cout<<endl<<"	MULTISET	"<<endl;
	multiset <int> m1;
	cout<<"is it empty? "<<m1.empty()<<endl;
	m1.insert(2);
	m1.insert(3);
	m1.insert(5);
	m1.insert(9);
	m1.insert(1);
	m1.insert(4);
	m1.insert(6);
	print(m1);
	
	m1.insert(2);
	m1.insert(2);
	m1.insert(2);
	m1.insert(2);
	print(m1);

	cout<<"how many 2 are there? :"<<m1.count(2)<<endl;
	
	//! lower_bound elemanýn bulunduðu alt sýnýrý,upper_bound üst sýnýrý verir. erase fonksiyonu verilen aralýktaki verileri siler.
	m1.erase(m1.lower_bound(2),m1.upper_bound(2));//! bu iþlemle tüm 2 elemanlarý silinmiþ olur.
	print(m1);
	
	
	//! equal_range fonksiyonu parametre olarak aldýðý verinin bulunduðu aralýðý verir.
	//! burada yapýlan iþlem yukarýdaki iþlemle ayný iþi yapar
	m1.insert(2);
	m1.insert(2);
	m1.insert(2);
	m1.insert(2);
	print(m1);
	pair<multiset<int>::iterator,multiset<int>::iterator> range=m1.equal_range(2);
	m1.erase(range.first,range.second);
	print(m1);
}
