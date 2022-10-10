#include<iostream>
#include<list>

using namespace std;

template <typename T>
void print(T& x){
	typename T::iterator it = x.begin();
	
	if(x.empty()){
		cout<<"no element";
	}
	else{
		cout<<"Elements=>";
		while(it!=x.end()){
			cout<<*it<<" ";
			it++;
		}
	}
	
	cout<<endl;
}

int main(){
	list <int> l1;
	
	cout<<"is it empty? : "<<l1.empty()<<endl;//! liste boþluðunu kontrol eder
	
	//! insert fonksiyonu ile konum vererek ekleme
	l1.insert(l1.begin(),4); 
	l1.insert(l1.end(),5); 
	print(l1);
	cout<<"is it empty? : "<<l1.empty()<<endl;
	
	cout<<"first element:"<<*l1.begin()<<endl; //! l1.begin=>ilk elemanýn adresini verir. * iþareti ile adresteki elemana ulaþýrýz 
	cout<<"last element:"<<*l1.end()<<endl; //! son elemaný verir
	
	
	
	l1.push_back(2);//! sona ekleme yapar
	l1.push_front(6);//! baþa ekleme yapar
	print(l1);
	

	l1.reverse();//! listeyi ters çevirir
	print(l1);
	
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(7);
	print(l1);
	l1.remove(4); //! parametre ile verilen deðiþkeni listeden siler
	print(l1);
	
	
	l1.pop_back();//! sondan eleman siler
	print(l1);
	l1.pop_front();//! baþtan eleman siler
	print(l1);
	cout<<"size: "<<l1.size()<<endl;//! listenin boyutunu verir
	
	l1.unique();//! listeyi benzersiz yapar. birden fazla geçen elemaný teke düþürür
	print(l1);
	
	
	l1.erase(l1.begin());//! baþlangýç konumu vererek eleman siler. verilen konumdan sonraki tüm elemanlar silinir.
	print(l1);
	l1.erase(l1.begin(),l1.end()); //! aralýk vererek eleman silme iþlemi yapar
	print(l1);
	
	
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	print(l1);
	l1.clear();//! listeyi temizler
	print(l1);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(7);
	l1.push_back(7);//! bir eleman birden fazla kez eklenebilir
	l1.push_back(3);
	l1.push_back(8);
	l1.push_back(6);
	print(l1);
	
	
	l1.sort();//! liste elemanlarýný küçükten büyüðe sýralar
	print(l1);
	
	
	cout<<endl<<"	l2	"<<endl;
	list <int> l2(l1);
	print(l2);
	l2.push_back(8);
	l2.push_back(6);
	l2.push_back(5);
	
	cout<<endl<<"swap l1-l2"<<endl;
	cout<<"before l1 ";
	print(l1);
	cout<<"before l2 ";
	print(l2);
	
	
	l1.swap(l2);//! 2 farklý listenin elemanlarýný karþýlýklý deðiþtirir
	
	cout<<"after l1 ";
	print(l1);
	cout<<"after l2 ";
	print(l2);
	
	/*! verilen baþlangýç konumuna göre 2 listeyi birleþtirir. ancak eklenen liste içeriði silinir.
	son durumda l1 e ekleme yapýldý. l2 listesi boþ kaldý 
	*/
	l1.splice(l1.begin(),l2);
	print(l1);
	print(l2);
	
		
}
