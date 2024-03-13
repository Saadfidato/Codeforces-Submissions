///---------------------SAAD---------------------

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll N=600;


#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl cout<<"\n"
#define endl '\n'
#define cout(x) cout<<x<<"\n"
#define cout2(x,y) cout<<x<<" "<<y<<"\n"
#define cout3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define F first
#define S second
#define pb push_back

void arrayin(ll a[],ll len)
{
    for(ll i=0; i<len; i++) {
        cin>>a[i];
    }
}

void arrayout(ll a[],ll len)
{
    for(ll i=0; i<len; i++)
    {
        if(i==len-1) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
}
//void freq_array(ll a[],ll len){ for(ll i=0; i<len; i++){ cin>>a[i]; freq[a[i]]++;} }
/*void fact_array()
{
    for(ll i=0; i<N; i++)
    {
        if(i>1) fact[i] = i*fact[i-1];
        else fact[i]=1;
    }
}


void primenum(vector<bool> &prime)
{
    prime[0]=prime[1]=0;

    for(ll i=2; i<=N/2 ; i++)
    {
        if(prime[i]==1) {
            for(ll j=i+i; j<=N; j+=i) {
                prime[j]=0;
            }
        }
    }
}
ll factorial(ll n)
{
    if(n==0) return 1;
    return n*factorial(n-1);
}*/

double distance(double a,double b,double x,double y)
{
    return sqrt((a-x)*(a-x)+(b-y)*(b-y));
}


void tc()
{
    ///vector<bool> prime(N,1);  primenum(prime);
    ///fact_array();

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll ar[n];
        arrayin(ar,n);

        ll ck,a,b,sum=1,sum2=1;
        cin>>ck;

        ll p[n],q[n];

        p[0]=0; p[1]=1;
        q[n-1]=0; q[n-2]=1;

        for(ll i=2; i<n; i++)
        {
            if(ar[i]-ar[i-1] < ar[i-1]-ar[i-2]) sum+=1;
            else sum+=ar[i]-ar[i-1];

            p[i]=sum;
        }

        for(ll i=n-3; i>=0; i--)
        {
            if( ar[i+1]-ar[i] < ar[i+2]-ar[i+1]) sum2+=1;
            else sum2+=ar[i+1]-ar[i];

            q[i]=sum2;
        }

        while(ck--)
        {
            cin>>a>>b;

            a--;    b--;

            ll ans;

            if(a==b) ans=0;
            else if(a<b) ans=p[b]-p[a];
            else ans=q[b]-q[a];

            cout(ans);
        }
    }
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    tc();

    return 0;
}