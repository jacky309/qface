{# Copyright (c) Pelagicore AB 2016 #}
{% import "qtcpp.j2" as cpp %}
{% set class = 'QmlAbstract{0}'.format(interface) %}
/****************************************************************************
** This is an auto-generated file.
** Do not edit! All changes made to it will be lost.
****************************************************************************/


#pragma once

#include <QtCore>

#include "{{module.module_name|lower}}module.h"

class {{class}} : public QObject
{
    Q_OBJECT
{% for property in interface.properties %}
    {{ cpp.property(property)}}
{% endfor %}

public:
    {{class}}(QObject *parent = nullptr);
    ~{{class}}();

public Q_SLOTS:
{% for operation in interface.operations %}
    {{ cpp.operation_decl(operation) }}
{% endfor %}
public:
{% for property in interface.properties %}
    {{ cpp.property_setter_decl(property) }}
{% endfor %}
public:
{% for property in interface.properties %}
    {{cpp.property_getter_decl(property) }}
{% endfor %}
Q_SIGNALS:
{% for signal in interface.signals %}
    {{ cpp.signal_decl(signal)}}
{% endfor %}
{% for property in interface.properties %}
    {{ cpp.signal_decl(property) }}
{% endfor %}
protected:
{% for property in interface.properties %}
    {{ cpp.property_member_decl(property) }}
{% endfor %}
};
