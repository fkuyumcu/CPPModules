class Fixed
{
    public:
    Fixed();
    Fixed(const Fixed &f);
        
    ~Fixed();



    private:
    int fixed_value;
    static const int num_of_fractional = 8;


};