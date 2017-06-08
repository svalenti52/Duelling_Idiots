/** \file utilities.hpp
 *
 */

#include <vector>
#include <iostream>

class Bin
{
public:
	double right_edge_interval;
	int count;
public:
	Bin(double i_right_edge_interval) :
		right_edge_interval(i_right_edge_interval),
		count(0) {}
	bool inc_count_if_less_than(double v)
		{
			if ( v < right_edge_interval )
			{
				++count;
				return true;
			}
			return false;
		}
	friend std::ostream& operator <<(std::ostream& o, Bin& b);
};

std::ostream& operator <<(std::ostream& o, Bin& b)
		{
			o << b.count << " ";
			return o;
		}

/*-----------------------------------------------------------*/

class Bins
{
	int nr_bins;
	std::vector<Bin> bins;
public:
	Bins(int i_nr_bins, double value_sz) :
		nr_bins(i_nr_bins)
		{
			double first_right_edge = value_sz / static_cast<double>(nr_bins);
			bins.push_back(Bin(first_right_edge));
			for ( int ix = 1; ix < nr_bins; ++ix )
				bins.push_back(Bin(first_right_edge *(ix+1)));
		}
	void inc_bin_by_val(double val)
		{
			for ( Bin& b : bins )
				if ( b.inc_count_if_less_than(val) )
					break;
		}
	friend std::ostream& operator <<( std::ostream& o, Bins& bins );
};

std::ostream& operator <<( std::ostream& o, Bins& bins )
		{
			for ( Bin& b : bins.bins )
				o << b;
			return o;
		}
