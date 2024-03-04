#ifndef GEOJSONCLASS_H
#define GEOJSONCLASS_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QGeoCoordinate>


class GeojsonClass
{
public:
    GeojsonClass(const QString& filename);

    void addLine(int lat1 , int lon1 , int lat2 , int lon2);
    void addX1(int lat1 , int lon1 );
    void addX2(int lat1 , int lon1 );

    
    void addPolygon(QGeoCoordinate coordinate1, QGeoCoordinate coordinate2  , QGeoCoordinate coordinate3 , QGeoCoordinate coordinate4 , QGeoCoordinate coordinate5);


    void writeToFile ();


private:

    QString filename_   ;
    QJsonObject geojson_;
    QJsonArray features_;



};

#endif // GEOJSONCLASS_H
