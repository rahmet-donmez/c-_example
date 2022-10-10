#include<iostream>
#include<stack>

using namespace std;

template <typename T>
void print(stack<T> x){
	
	if(x.empty()){
		cout<<"no element";
	}
	else{
		cout<<"Elements=>";
		while(!x.empty()){
			cout<<x.top()<<" ";
			x.pop();			
		}
	}
	
	cout<<endl;
}

int main(){
	stack <int> s1;
	cout<<"is it empty? : "<<s1.empty()<<endl;//! y���n�n bo� olma durumunu kontrol eder
	
	s1.push(1);//! y���na eleman ekler
	s1.push(8);
	s1.push(6);
	s1.push(5);
	print(s1);
	cout<<"is it empty? : "<<s1.empty()<<endl;
	
	cout<<"top element:"<<s1.top()<<endl; //! y���na son eklenen eleman� verir

	cout<<"size: "<<s1.size()<<endl;//! boyutu verir
	s1.pop();//! eleman ��kar�r
	print(s1);
	cout<<"size: "<<s1.size()<<endl;
	
	stack <int> s2(s1);
	cout<<endl<<"s2: ";
	print(s2);
	
		
}
