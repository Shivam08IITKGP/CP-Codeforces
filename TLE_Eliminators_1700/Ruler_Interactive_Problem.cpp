int query(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int area;
    cin >> area;
    return area;
}

void solve()
{
    int l = 1, r = 1000; // Given range of x
    while (r - l > 2)
    { // Ensuring at least 2 values remain
        int a = l + (r - l) / 3;
        int b = r - (r - l) / 3;
        int area = query(a, b); // Query the area of the rectangle
        if (area == a * b)
        {
            l = b;
        }
        else if (area == (a + 1) * (b + 1))
        {
            r = a;
        }
        else
        {
            l = a;
            r = b;
        }
    }

    if (r - l == 2)
    {
        int area = query(1, l + 1);
        if (area != (l + 1))
        {
            r = l + 1;
        }
    }

    cout << "! " << r << endl; // Output the final result
    cout.flush();
}
