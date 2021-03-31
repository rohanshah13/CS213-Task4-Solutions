#include <iostream>
using namespace std;
 
class bst{
     public: 
    long long x;
    int mi, ma;
    unsigned long long Mx;
    bst *left, *right;

   
    bst() {
        x = -1;
        Mx = -1;
        mi = -1;
        ma = -1;
        left = NULL;
        right = NULL;
    }

    long get(int xx, long add) {
        if (xx == x) return Mx+add;
        if(xx > x && right!=NULL) return right->get(xx, add + Mx);
        if(xx < x && left!=NULL) return left->get(xx, add + Mx);

        return -1;
    }

    void insert(int xx, long yy) {
        mi = min(mi,xx);
        ma = max(ma,xx);
        if(x == -1) {
            x = xx;
            mi = xx;
            ma = xx;
            Mx = yy;
            return;
        }
        if(x < xx) {
            if(right==NULL) right = new bst;
            right->insert(xx,yy-Mx);
        }
        else if(x>xx){
            if(left==NULL) left = new bst;
            left->insert(xx,yy-Mx);
        }
        else{
            if(left!=NULL) left->Mx += Mx-yy;
            if(right!=NULL) right->Mx += Mx - yy;
            Mx = yy;
        }
    }

    void pass(bst * l) {
        mi = min(mi,l->mi);
        ma = max(ma,l->ma);
        l->Mx -= Mx;
        if(left==NULL) left = l;
        else left->pass(l);
    }

    int del(int xx) {
        // // cout<<"del"<<endl;
        if(xx < x && left!=NULL) 
        {
            // cout<<"left"<<endl;
            if(left->del(xx)==1){
                delete left;
                // cout<<"delete left"<<endl;
                left = NULL;
                mi = x;
            }
            else {
                mi = left->mi;
            }

        }
        else if(xx > x && right!=NULL) 
        {
            // cout<<"right "<<xx<<" "<<x<<endl;
            if(right->del(xx)==1) {
                delete right;
                right = NULL;
                ma = x;
            }
            else {
                ma = right->ma;
            }
        }
        else if(xx==x){
            // // cout<<"del"<<endl;
            if(left == NULL) {
                // cout<<"r"<<endl;
                if(right !=NULL) {
                    // cout<<"r"<<endl;
                    x = right->x;
                    Mx += right->Mx;
                    left = right->left;
                    bst* temp = right->right;
                    delete right; 
                    right = temp;
                }
                else {
                    // cout<<"leaf"<<endl;
                    return 1;
                }
            }
            else if(right == NULL) {
                // cout<<"l"<<endl;
                if(left !=NULL) {   
                    // cout<<left->x<<endl;
                    x = left->x;
                    Mx += left->Mx;
                    bst* temp = left->left;
                    right = left->right;
                    delete left;
                    left = temp; 
                }
            }
            else {
                // cout<<"top"<<endl;
                right->pass(left);
                // print();
                x = right->x;
                Mx += right->Mx;
                left = right->left;
                bst* temp = right->right;
                delete right;
                right = temp; 
            }
        }
        return 0;
    }

    void add(int x1, int x2, long c) {
        // cout<<x<<' '<<x1<<" "<<x2<<" "<<c<<endl;
        if(ma<x1 || (mi>x2 && x2!=-1)) return;
        if(right!=NULL && x1>x) {
            // cout<<"right"<<endl;
            right->add(x1,x2,c);
        }
        else if(left!=NULL && x2!=-1 && x2<x) {
            // cout<<"left"<<endl;
            left->add(x1,x2,c);
        }
        else if((x >= x1 && x<= x2) || (x2==-1 && x>=x1)||(x1==0 && x<=x2) ){
            // cout<<"in"<<endl;
            Mx+=c;
            if(left!=NULL && x1!=0) left->add(0,x1-1,-c);
            if(right!=NULL && x2!=-1) right->add(x2+1,-1,-c);
        }
    }
    void print(){
        cout<<x<<"["<<Mx<<"]( ";
        if(left!=NULL)        left->print();
        
        cout<<") ";
        if(right!=NULL) right->print();
    }
};

int main() {
    char c;
    bst* a = NULL;
    a = new bst;
    bool flag = false;
    while(1) {
        // cout<<"-----------------------"<<endl;
        // a->print();
        // cout<<endl;
        c = getchar();
        switch(c) {
            case 'g': {
                int xx;
                cin>>xx;
                long ans = a->get(xx,0);
                // cout<<xx<<" ";
                if(ans!=-1) {
                    cout<<ans<<endl;
                }
                // cout<<endl;
            }; break;
            case 'i': {
                int xx,yy;
                cin>>xx>>yy;
                a->insert(xx,yy);
            }; break;
            case 'd': {
                int xx;
                cin>>xx;
                if( a->del(xx)  == 1) {
                    delete a;
                    a = new bst;
                };
            }; break;
            case 'a': {
                int x1,x2;
                long c;
                cin>>x1>>x2>>c;
                a->add(x1,x2,c);
            }; break;
            case 'e': {
                flag = true;
            }
        }
        if(flag) break;
    }
}
