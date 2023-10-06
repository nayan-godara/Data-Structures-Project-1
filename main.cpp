#include<iostream>
#include<vector>
using namespace std;
class SET{
    public:
        SET(){
            ;
        }
        vector <int> Elements={};
        int binary(vector<int>vec,int a,int l,int r){
            
            int mid;
            int value=0;
            if(l==r){
                return l;
            }else{
            while(r-l>0){
                mid=(l+r)/2;
                if(vec[mid]>a){
                    r=mid-1;
                }
                else if(vec[mid]==a){
                    value=1;
                    break;
                }
                else{
                    l=mid+1;
                }
            
            }
            if(value==1){
                return mid;

            }else{
                return l;
            }
            }
        }
        void pushafter(vector <int> &Elements,int a,int b){
            if(b==Elements.size()-1){
                Elements.push_back(a);
            }else{
            Elements.push_back(0);
            for(int i=Elements.size()-1;i>=b+2;i--){
                Elements[i]=Elements[i-1];

            }
            Elements[b+1]=a;
            }

        }
        void pushbefore(vector<int> &Elements,int a,int b){
            Elements.push_back(0);
            for(int i=Elements.size()-1;i>=b+1;i--){
                Elements[i]=Elements[i-1];

            }
            Elements[b]=a;

            

        }
        void insert(int a){
            if(Elements.empty()){
                Elements.push_back(a);
            }else{
            int l=0;
            int r=Elements.size()-1;
            
            int b=binary(Elements,a,l,r);
            
            if(Elements[b]!=a){
                if(Elements[b]>a){
                    pushbefore(Elements,a,b);
                    

                }
                else if(Elements[b]<a){
                    pushafter(Elements,a,b);
                }


            }
            }
            cout<<Elements.size()<<"\n";
            
        }
        void Delete(int a){
            if(Elements.size()==0){
                cout<<0<<"\n";
            }else{
            int b=binary(Elements,a,0,Elements.size()-1);
            int size =Elements.size();
            if(Elements[b]==a){
                for(int i=b;i<size-1;i++){
                    Elements[i]=Elements[i+1];
                    

                }
                Elements.pop_back();
            }
            cout<<Elements.size()<<"\n";
            }
            
        }
        void Belongs_To(int a){
            if(Elements.size()==0){
                cout<<0<<"\n";
            }
            else{
            int b=binary(Elements,a,0,Elements.size()-1);
            if(Elements[b]==a){
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
            }
        }
        void Union(SET A){
            if(Elements.size()==0 && A.Elements.size()==0){
                cout<<0<<"\n";
            }
            else if(Elements.size()==0){
                Elements=A.Elements;
                cout<<Elements.size()<<"\n";
            }
            else if(A.Elements.size()==0){
                cout<<Elements.size()<<"\n";
            }
            else{
                vector<int> un=Elements;
                for(int i=0;i<A.Elements.size();i++){
                    int b= binary(un,A.Elements[i],0,un.size()-1);
                    if(un[b]!=A.Elements[i]){
                        if(un[b]>A.Elements[i]){
                            un.insert(un.begin()+b,A.Elements[i]);
                        }
                        else{
                            if(b==un.size()-1){
                                un.push_back(A.Elements[i]);

                            }
                            else{
                                un.insert(un.begin()+b+1,A.Elements[i]);
                            }

                        }
                    }
                }
                Elements=un;
                cout<<Elements.size()<<"\n";
            }

        }
        void Intersection(SET A){
            if(Elements.size()==0 && A.Elements.size()==0){
                cout<<0<<"\n";
            }
            else if(Elements.size()==0){
                cout<<0<<"\n";
                 

            }
            else{int l=0;
            int r=Elements.size()-1;
            vector<int>inter={};
            
            
            for(int i=0;i<A.Elements.size();i++){
                int b=binary(Elements,A.Elements[i],l,r);
                if(Elements[b]==A.Elements[i]){
                    inter.push_back(A.Elements[i]);
                    
                    
                    
                }
                
            }
            Elements=inter;
            
            
            
            cout<<Elements.size()<<"\n";
            }
            
        }
        void Size(){
            cout<<Elements.size()<<"\n";
        }
        vector<int> DifferenceSet1(vector<int> Elements, SET A) {
    vector<int> diff={};
    if(A.Elements.size()==0){
        return Elements;
    }
    else{
    for (int i = 0; i < Elements.size(); i++) {
        int l = 0;
        int r = A.Elements.size() - 1;
        int b = binary(A.Elements, Elements[i], l, r);
        
        if (Elements[i] != A.Elements[b]) {
            diff.push_back(Elements[i]);
        }
    }
    
    return diff;
    }
}

        vector<int> DifferenceSet2(vector<int> Elements, SET A) {
    vector<int> diff={};
    if(Elements.size()==0){
        return A.Elements;
    }
    else{
    for (int i = 0; i < A.Elements.size(); i++) {
        int l = 0;
        int r = Elements.size() - 1;
        int b = binary(Elements, A.Elements[i], l, r);
        
        if (A.Elements[i] != Elements[b]) {
            diff.push_back(A.Elements[i]);
        }
    }
    
    return diff;
    }
}
        void difference(SET A){
            vector<int> diff=DifferenceSet1(Elements,A);
            
            Elements.swap(diff);
            cout<<Elements.size()<<"\n";
            


        }
        

        vector<int> mergeSortedVectors(const vector<int>& vec1, const vector<int>& vec2) {
    
    vector<int> merge={};
    if(vec1.size()==0 && vec2.size()==0){
        return merge;
    }
    else if(vec1.size()==0){
        return vec2;

    }
    else if(vec2.size()==0){
        return vec1;
    }
    else{
    size_t i = 0;
    size_t j = 0;
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();

    while (i < size1 && j < size2) {
        if (vec1[i] < vec2[j]) {
            merge.push_back(vec1[i]);
            i++;
        } else {
            merge.push_back(vec2[j]);
            j++;
        }
    }

    
    while (i < size1) {
        merge.push_back(vec1[i]);
        i++;
    }

    
    while (j < size2) {
        merge.push_back(vec2[j]);
        j++;
    }

    return merge;
    }
}

        void symmdiff(SET A){
            vector<int> diff1=DifferenceSet1(Elements,A);
            vector<int> diff2=DifferenceSet2(Elements,A);
            while(!Elements.empty()){
                Elements.pop_back();
            }
            Elements=mergeSortedVectors(diff1,diff2);
            cout<<Elements.size()<<"\n";
            
        
        }
        void Print(){
            if(Elements.size()==0){
                cout<<"\n";
            }else{
            for(int i=0;i<Elements.size()-1;i++){
                cout<<Elements[i]<<",";
            }
            cout<<Elements[Elements.size()-1]<<"\n";
            }
        }
};




int main(){
    
    SET sets[100001];
    int input;
    int exist[100001];
    for(int i=0;i<10001;i++){
        exist[i]=0;
    }
    while(cin>>input){
        if(input==1){
            int set_num;
            cin>>set_num;
            if(exist[set_num]==1){
                int num;
                cin>>num;
                sets[set_num].insert(num);
            }else{
                exist[set_num]=1;
                sets[set_num]=SET();
                int num;
                cin>>num;
                sets[set_num].insert(num);
                
                

            }
            

        }
        else if(input==2){
            int set_num;
            cin>>set_num;
            if(exist[set_num]==1){
                int num;
                cin>>num;
                sets[set_num].Delete(num);
            }else{
                int num;
                cin>>num;
                exist[set_num]=1;
                sets[set_num]=SET();
                cout<<-1<<"\n";
            }

        }
        else if(input==3){
            int set_num;
            cin>>set_num;
            if(exist[set_num]==1){
                int num;
                cin>>num;
                sets[set_num].Belongs_To(num);
            }else{
                int num;
                cin>>num;
                
                
                cout<<-1<<"\n";
            }
        }
        else if(input==4){
            int set1,set2;
            cin>>set1>>set2;
            if(exist[set1]==1 &&exist[set2]==1){
                sets[set1].Union(sets[set2]);
            }
            else if(exist[set1]==0 &&exist[set2]==1){
               
                exist[set1]=1;
                
                sets[set1]=sets[set2];
                
                sets[set2].Size();
                
            }
            else if(exist[set1]==1 &&exist[set2]==0){
                exist[set2]=1;
                sets[set2]=SET();
                sets[set1].Size();
                

            }
            else{
                exist[set1]=1;
                sets[set1]=SET();
                exist[set2]=1;
                sets[set2]=SET();
                cout<<0<<"\n";
            }

        }
        else if(input==5){
            int set1,set2;
            cin>>set1>>set2;
            if(exist[set1]==1 &&exist[set2]==1){
                sets[set1].Intersection(sets[set2]);
                
            }
            else if(exist[set1]==0 &&exist[set2]==1){
                exist[set1]=1;
                sets[set1]=SET();
                cout<<0<<"\n";

            }
            else if(exist[set1]==1 &&exist[set2]==0){
                exist[set2]=1;
                sets[set2]=SET();
                cout<<0<<"\n";


            }
            else{
                exist[set1]=1;
                sets[set1]=SET();
                exist[set2]=1;
                sets[set2]=SET();
                cout<<0<<"\n";

            }

        }
        else if(input==6){
            int num;
            cin>>num;
            if(exist[num]==1){
                sets[num].Size();
            }
            else{
                exist[num]=1;
                sets[num]=SET();
                cout<<0<<"\n";
            }
        }
        else if(input==7){
            int set1,set2;
            cin>>set1>>set2;
            if(exist[set1]==1 &&exist[set2]==1){
                sets[set1].difference(sets[set2]);
            }
            else if(exist[set1]==0 &&exist[set2]==1){
                exist[set1]=1;
                sets[set1]=SET();
                cout<<0<<"\n";

            }
            else if(exist[set1]==1 &&exist[set2]==0){
                exist[set2]=1;
                sets[set2]=SET();
                sets[set1].Size();


            }
            else{
                exist[set1]=1;
                sets[set1]=SET();
                exist[set2]=1;
                sets[set2]=SET();
                cout<<0<<"\n";

            }


        }
        else if(input==8){
            int set1,set2;
            cin>>set1>>set2;
            if(exist[set1]==1 &&exist[set2]==1){
                sets[set1].symmdiff(sets[set2]);
            }
            else if(exist[set1]==0 &&exist[set2]==1){
                exist[set1]=1;
                sets[set1]=sets[set2];
                sets[set2].Size();

            }
            else if(exist[set1]==1 &&exist[set2]==0){
                exist[set2]=1;
                sets[set2]=SET();
                sets[set1].Size();


            }
            else{
                exist[set1]=1;
                sets[set1]=SET();
                exist[set2]=1;
                sets[set2]=SET();
                cout<<0<<"\n";

            }
            
        }
        else if(input==9){
            int num;
            cin>>num;
            if(exist[num]==1){
                sets[num].Print();
            }
            else{
                cout<<"\n";
            }
        }
    }
    
}