{# Copyright (c) Pelagicore AB 2016 #}
{% import "qtcpp.j2" as cpp %}
/****************************************************************************
** This is an auto-generated file.
** Do not edit! All changes made to it will be lost.
****************************************************************************/
{% set class = '{0}Module'.format(module.module_name) %}

#pragma once

#include <QtCore>

#include "variantmodel.h"
{% for struct in module.structs %}
#include "{{struct|lower}}.h"
#include "{{struct|lower}}model.h"
{% endfor %}

class {{class}} : public QObject {
    Q_OBJECT
public:
    {{class}}(QObject *parent = nullptr);

{% for enum in module.enums %}
{{ cpp.enum_decl(enum) }}
{% endfor %}

{% for struct in module.structs %}
    Q_INVOKABLE {{struct}} create{{struct}}();
{% endfor %}

    static void registerTypes();
    static void registerQmlTypes(const QString& uri, int majorVersion = 1, int minorVersion = 0);
};
