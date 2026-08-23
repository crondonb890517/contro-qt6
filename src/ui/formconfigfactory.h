#ifndef FORMCONFIGFACTORY_H
#define FORMCONFIGFACTORY_H

#include "ui/genericdialog.h"

class FormConfigFactory
{
public:
    static FormConfig createContractFormConfig();
    static FormConfig createEntidadFormConfig();
};

#endif // FORMCONFIGFACTORY_H
