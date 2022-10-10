#include<iostream>
#include<queue>

using namespace std;

template <typename T>
void print(queue<T> x){

	if(x.empty()){
		cout<<"no element"<<endl;
	}
	else{
	
		cout<<"Elements=>";
		while(!x.empty()){
			cout<<x.front()<<" ";
			x.pop();
			
		}
	}
	
	cout<<endl;
}

template <typename T>
void print_priorty(priority_queue<T> x){

	if(x.empty()){
		cout<<"no element"<<endl;
	}
	else{
	
		cout<<"Elements=>";
		while(!x.empty()){
			cout<<x.top()<<" ";//! queue dan farký first yoktur top vardýr
			x.pop();
			
		}
	}
	
	cout<<endl;
}


int main(){
	queue <int> q1;
	
	cout<<"is q1 empty? : "<<q1.empty()<<endl;
	
	//! kuyruða ekleme yapar
	q1.push(9);
	q1.push(1);
	q1.push(6);
	q1.push(2);
	q1.push(1);
	cout<<"q1: ";
	print(q1);
	cout<<"is q1 empty? : "<<q1.empty()<<endl;//! kuyruðun boþ olma durumunu kontrol eder
	
	cout<<q1.front()<<endl;//! ilk elemaný verir
	cout<<q1.back()<<endl;//! son elemaný verir
	
	
	q1.pop();//! kuyruktan eleman siler. her zaman baþtan silme iþlemi yapar
	cout<<"q1: ";
	print(q1);
	
	cout<<"q1 size: "<<q1.size()<<endl;//! kuyruk boyutunu verir
	
	queue <int> q2(q1);
	cout<<"q2: ";
	print(q2);
	cout<<"q2 size: "<<q1.size()<<endl;
	

	//!PRIORITY QUEUE

/*! priorty queue nun queue dan farký elemanlarýn öncelik durumuna göre sýralanmasýdýr. 
geçerli olan öncelik durumu büyük olan elemandýr
*/
	priority_queue<int> p_q;
	cout<<endl<<"is p_q empty? : "<<p_q.empty()<<endl;
	p_q.push(2);
	p_q.push(4);
	p_q.push(5);
	p_q.push(2);
	p_q.push(9);
	cout<<"p_q: ";
	print_priorty(p_q);
	cout<<"is p_q empty? : "<<p_q.empty()<<endl;	
	p_q.pop();
	cout<<"p_q: ";
	print_priorty(p_q);
			
}
