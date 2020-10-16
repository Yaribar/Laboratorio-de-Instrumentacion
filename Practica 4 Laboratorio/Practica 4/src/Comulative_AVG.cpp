
#include "Comulative_AVG.h"

AVG::AVG()
{
}
AVG::~AVG()
{
}

void AVG::avg(uint16_t dato)
{
    _acumulative_avg = (_acumulative_avg * (_count / (_count + 1))) + (float(dato) * (1.0 / (_count + 1.0)));
    _count = _count + 1.0;
}
void AVG::resetAvg()
{
    _acumulative_avg = 0;
    _count = 0;
}

float AVG::getCurrentAvg() //Indicar que pertenece a la clase AVG
{
    return _acumulative_avg;
}