
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    read(a);
    b[0] = a[0];
    int max_b= b[0];
    int max_a= a[0];
    int max_bit=0;

  // We can add any number to a[i] not necesarily 1 3 7 15 or 2^k-1
  // The bits of the number added can be for example like 1101 i.e add 8,4,1 only
  // b is the final array
  // We need the minimize the maximum bit used in b[i]-a[i]
  // b[i] is maximum among all the b before index i and a[i]
    for(int i=1;i<n;i++)
    {
        b[i] = max(max_b,max_a);
        //max bit of b[i]-a[i]
        int bit= 0;
        int temp= b[i]-a[i];
        while(temp>0)
        {
            temp/=2;
            bit++;
        }
        max_bit= max(max_bit,bit );
        max_b= max(max_b,b[i]);
        max_a= max(max_a,a[i]);

    }
    cout<<max_bit<<endl;
}
