
#include "Comulative_AVG.h"

AVG::AVG()
{

}
AVG::~AVG()
{
    
}

float AVG::avg(float dato)
{
    _acumulative_avg=_acumulative_avg*(_count/(_count+1))+dato*(1/(_count+1));
    _count+=1;
    return _acumulative_avg;
}
void AVG::resetAvg()
{
    _acumulative_avg=0;
    _count=0;
}
