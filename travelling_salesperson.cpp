
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
    int sm;
    string s;
};

int str_int(string x)
{
    stringstream a(x);
    int b;
    a>>b;
    return b;
}

string int_str(int x)
{
    stringstream a;
    a<<x;
    return a.str();
}

int getVal(int i,string s)
{
    string x=int_str(i)+s;
    int t=str_int(x);
    return (t);
}

//unordered_map<string, double> umap;
unordered_map<string, node> Hash;

class graph
{
    public:
    int V; //static int N;

   	graph(int v)
	{
        V=v;
    }
    int arr[25][25]={{0}};//=new int[N];//[]=new int[N][N];
    //arr[0][0]=0;

    void addVertex()
	{
		V++;
	}

	void addEdge(int a,int A[])
	{
	    if(a>V-1)
        {
            cout<<"Error : Vertex not found"<<endl;
            return;
        }
        for(int i=0;i<V;i++)
        {
            arr[a][i]=A[i];
        }
	}


	void addEdge(int a, int b,int wt)
	{
	    if(a>V-1 || b>V-1)
        {
            cout<<"Error : Vertex not found"<<endl;
            return;
        }
		arr[a][b]=wt;
	}

};


node TSP(int i, list <int> A,int arr[25][25],string sum )
{
    int minm = INT_MAX; string str;
    if(A.empty())
    {
        node a; a.sm=arr[i][0];
        a.s=int_str(i);

        return a;
    }
    int l=A.size();
    int a1=getVal(i,sum);

    if(Hash.find(a1) != Hash.end()))
    {
        return Hash.find(a1);
    }

    for(int j=0; j<l;j++)
    {

        if(arr[i][A.front()]==0)
        {
            A.push_back(A.front());
            A.pop_front();
            continue;
        }
        int t=A.front(); A.pop_front();
        sum.erase(0,1);

        int S; string st; node temp=TSP(t,A,arr,sum);

        if(temp.sm==INT_MAX)
        { S=temp.sm; }
        else
        { S=arr[i][t]+temp.sm; }
        st=int_str(i)+temp.s;

        if(S<minm) { minm=S; str=st; }
        A.push_back(t); sum=sum+int_str(t);
    }
    node x; x.sm=minm; x.s=str;
    Hash[a1]=x;

    return x;
}


void TSP_mn(graph x,int sp)
{
    list <int> a; string sm;
    for(int i=0; i< x.V; i++)
    {
        if(i!=sp)
        { a.push_back(i); sm=sm+int_str(i); }
    }
     node x1=TSP(sp,a,x.arr,sm);
     cout<<x1.sm<<" "<<x1.s;
}

int main()
{
    int x1;
    cout<<"Enter the no cities : "; cin>>x1;
    graph x(x1);
    int arr[x1];

    for(int i=0; i<x1;i++)
    {
        cout<<"Enter the "<<i<<" row :";

        for(int j=0;j<x1;j++)
        {
            cin>>arr[j];
        }
        x.addEdge(i,arr);

    }
    cout<<"\n\n";


    for(int i=0; i<x.V;i++)
    {
        for(int j=0;j<x.V; j++)
        {
            cout<<x.arr[i][j]<<" ";
        }
       cout<<"\n\n"<<endl;
    }


    TSP_mn(x,0);

	return 0;

}
