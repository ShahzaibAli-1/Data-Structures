#include<iostream>
using namespace std;
struct HashTable{

    int *arr;
    int size;

    HashTable(int s){
        this->size  = s;
        this->arr = new int[size];
        for(int i = 0;i<size;i++){
            arr[i] = -1;
        }
    }
    bool checkcolision(int index){
        if(arr[index]==-1){
            return false;
        }
        return true;
    }
    bool checkFull(){
        for(int i = 0;i<size;i++){
            if (arr[i]==-1){
                return false;
            }
        }
        return true;
    }
    int HashFuntion(int number){
        return number%size;
    }
    void LinearProbing( int number){
        for(int i = 1;i<size;i++){
            int new_index = HashFuntion(number+i);
            if(arr[new_index] == -1){
                arr[new_index] = number;
                return;
            }
        }
    }
    void insert(int number){
        if(checkFull()){
            cout<<"Array is full\n";
            return;
        }
        int index = number%size;
        //If there is no collision
        if (!checkcolision(index)){
            arr[index] = number;
        }
        else{
            LinearProbing(number);
        }
    }
    void show_array(){
        for(int i = 0 ;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    bool search_key(int number){
        int first_index = HashFuntion(number);
        if (number==arr[first_index]){
            cout<<"\nKey Found\n";
            return true;
        }
        else {
            for(int i= 1 ; i<size;i++){
                int new_index = HashFuntion(number+i);
                if(arr[new_index] == number){
                    cout<<"\nKey Found\n";
                    return true;
                }
            }
        }
        cout<<"\nKey NOT Found\n";
        return false;
    }
};
int main(){
HashTable h1(5);
h1.insert(6);
h1.insert(3);
h1.insert(33);
h1.insert(53);
h1.show_array();
h1.search_key(59);
    return 0;
}