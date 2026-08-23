#ifndef FORMCONFIGFACTORY_H
#define FORMCONFIGFACTORY_H

#include "ui/genericdialog.h"

class FormConfigFactory
{
public:
    static FormConfig createContractFormConfig();
    static FormConfig createEntidadFormConfig();
    static GridConfig createContratosConfig();
    static GridConfig createEntidadesConfig();
};

#endif // FORMCONFIGFACTORY_H
