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
	
	cout<<"is it empty? : "<<l1.empty()<<endl;//! liste bo�lu�unu kontrol eder
	
	//! insert fonksiyonu ile konum vererek ekleme
	l1.insert(l1.begin(),4); 
	l1.insert(l1.end(),5); 
	print(l1);
	cout<<"is it empty? : "<<l1.empty()<<endl;
	
	cout<<"first element:"<<*l1.begin()<<endl; //! l1.begin=>ilk eleman�n adresini verir. * i�areti ile adresteki elemana ula��r�z 
	cout<<"last element:"<<*l1.end()<<endl; //! son eleman� verir
	
	
	
	l1.push_back(2);//! sona ekleme yapar
	l1.push_front(6);//! ba�a ekleme yapar
	print(l1);
	

	l1.reverse();//! listeyi ters �evirir
	print(l1);
	
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(7);
	print(l1);
	l1.remove(4); //! parametre ile verilen de�i�keni listeden siler
	print(l1);
	
	
	l1.pop_back();//! sondan eleman siler
	print(l1);
	l1.pop_front();//! ba�tan eleman siler
	print(l1);
	cout<<"size: "<<l1.size()<<endl;//! listenin boyutunu verir
	
	l1.unique();//! listeyi benzersiz yapar. birden fazla ge�en eleman� teke d���r�r
	print(l1);
	
	
	l1.erase(l1.begin());//! ba�lang�� konumu vererek eleman siler. verilen konumdan sonraki t�m elemanlar silinir.
	print(l1);
	l1.erase(l1.begin(),l1.end()); //! aral�k vererek eleman silme i�lemi yapar
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
	
	
	l1.sort();//! liste elemanlar�n� k���kten b�y��e s�ralar
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
	
	
	l1.swap(l2);//! 2 farkl� listenin elemanlar�n� kar��l�kl� de�i�tirir
	
	cout<<"after l1 ";
	print(l1);
	cout<<"after l2 ";
	print(l2);
	
	/*! verilen ba�lang�� konumuna g�re 2 listeyi birle�tirir. ancak eklenen liste i�eri�i silinir.
	son durumda l1 e ekleme yap�ld�. l2 listesi bo� kald� 
	*/
	l1.splice(l1.begin(),l2);
	print(l1);
	print(l2);
	
		
}
