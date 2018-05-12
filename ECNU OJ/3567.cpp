#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;

char s[200000],t[200000];
int arrs[200000],arrt[200000];
int lens,lent;
int main(){
    ll k;
    int counter[4];
    scanf("%d%d%lld",&lens,&lent,&k);
    if(lens<lent){
        scanf("%s%s",t,s);
        swap(lens,lent);
    }
    else
        scanf("%s%s",s,t);

    for(int i=0;i<lens;i++){
        if(s[i]=='A')arrs[i]=0;
        else if (s[i]=='G')arrs[i]=1;
        else if(s[i]=='C')arrs[i]=2;
        else arrs[i]=3;
    }
    for(int i=0;i<lent;i++){
        if(t[i]=='A')arrt[i]=0;
        else if (t[i]=='G')arrt[i]=1;
        else if(t[i]=='C')arrt[i]=2;
        else arrt[i]=3;
    }

    ll gcdst = __gcd(lens,lent);
    ll lcmst = lens;
    lcmst = lcmst*lent/gcdst;
    ll ans = 0;
    ll cir = k/lcmst;
    ll cirt = (k%lcmst)/lent;
    for(int mo=0;mo<gcdst;mo++){
        ll ansmo=0;
        memset(counter,0,sizeof counter);
        for(int i=mo;i<lens;i+=gcdst)
            counter[arrs[i]]++;
        for(int i=mo;i<lent;i+=gcdst)
            ansmo+=counter[arrt[i]];
        ans += ansmo*cir;
        memset(counter,0,sizeof counter);
        int pos1=mo;
        for(int i=0;i<cirt;i++){
            counter[arrs[pos1]]++;
            pos1 += lent;
            pos1 %= lens;
        }
        int pos2 = mo;
        do{
            if(pos2<lent)
                ans += counter[arrt[pos2]];
            counter[arrs[pos2]]--;
            counter[arrs[pos1]]++;
            pos1 += lent;
            pos1 %=lens;
            pos2 += lent;
            pos2 %= lens;
        }while(pos2 != mo);
        ll le = cirt * lent;
        ll ri = k%lcmst;
        for(ll i=le+mo;i<ri;i+=gcdst){
            if(arrs[i%lens] == arrt[i%lent])
                ans++;
        }
    }
    printf("%lld\n",ans);

    return 0;
}
