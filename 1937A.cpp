void solve()
{
    int n;
    cin>>n;
    string s[2];
    cin>>s[0];
    cin>>s[1];
    int i=0,j=1;
    //i and j are counter variables, 
    //not the row and column of the matrix
    while(j<n)
    {
        //Down direction char is smaller than the Right direction char.
        if(s[0][j]=='1' and s[1][j-1]=='0')
            break;
        //If characters differ, we must increase i to become j.
        else if(s[0][j]!= s[1][j-1])
            i=j;
        //If both directions are the same, then increasing i is unnecessary.
        else (){}       
          
        j++;
    }
    for(int k=0;k<j;k++)
    {
        cout<<s[0][k];

    }
    for(int k=j-1;k<n;k++)
    {
        cout<<s[1][k];
    }
    cout<<endl;
    cout<<j-i<<endl;
}
