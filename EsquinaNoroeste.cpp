#include<bits/stdc++.h>
using namespace std;



int main()
{
    int N,M;
    cin>>N>>M;


    vector<vector<float>> v,acumulado;
    vector<float> asignar;
    float costo=0;

    asignar.assign(M,0);
    acumulado.assign(N,asignar);

    for(int i=0;i<N;i++)
    {
        vector<float> aux;
        for(int j=0;j<M;j++)
        {
            float aux1;
            cin>>aux1;
            aux.push_back(aux1);
        }
        v.push_back(aux);
    }

    int i=0;
    int j=0;
    while(true)
    {
        float minimo=min(v.at(N-1).at(j),v.at(i).at(M-1));
        //cout<<v.at(N-1).at(j)<<","<<v.at(i).at(M-1)<<endl;

        v.at(N-1).at(j)-=minimo;
        v.at(i).at(M-1)-=minimo;

        acumulado.at(i).at(j)=minimo;
        costo+=v.at(i).at(j)*minimo;

        if(v.at(i).at(M-1)==0)
            i++;
        if(v.at(N-1).at(j)==0)
            j++;
        if((v.at(N-1).at(i)==0 && v.at(i).at(M-1)==0) || (i==N-1 && j==M-1))
            break;

    }








    cout<<endl<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            if(j!=M-1 && i!=N-1 )
                cout<<v.at(i).at(j)<<"|"<<acumulado.at(i).at(j)<<"\t";
            else
                cout<<0<<"\t";

        cout<<endl;
    }
    cout<<endl;
    cout<<"Costo Total: "<<costo<<endl<<endl;



    return 0;
}
