#include "geojsonclass.h"

GeojsonClass::GeojsonClass(const QString& filename):filename_(filename)
{

    geojson_["type"] = "FeatureCollection" ;
    geojson_["name"] = "geo" ;


}

void GeojsonClass::addLine(int lat1, int lon1, int lat2, int lon2)
{
    QJsonObject feature;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"]="Feature";
    feature["properties"] = properties ;
    geometry["type"] = "LineString" ;
    coordinates.append(QJsonArray({lat1,lon1}));
    coordinates.append(QJsonArray({lat2,lon2}));

    geometry["coordinates"] = coordinates ;
    feature["geometry"] = geometry ;

    features_.append(feature) ;





}

void GeojsonClass::addX1(int lat1, int lon1)
{



    QJsonObject feature ;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"] = "Feature" ;
    feature["properties"]=properties ;
    geometry["type"] = "LineString" ;
    coordinates.append(QJsonArray({lat1,lon1}));
    coordinates.append(QJsonArray({lat1 - 2 , lon1-1})) ;
    geometry["coordinates"]=coordinates;
    feature["geometry"]=geometry;
    features_.append(feature) ;

}

void GeojsonClass::addX2(int lat1, int lon1)
{
    QJsonObject feature ;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"] = "Feature" ;
    feature["properties"]=properties ;
    geometry["type"] = "LineString" ;
    coordinates.append(QJsonArray({-lat1,lon1}));
    coordinates.append(QJsonArray({-lat1 + 2 , lon1-1})) ;
    geometry["coordinates"]=coordinates;
    feature["geometry"]=geometry;
    features_.append(feature) ;
}

void GeojsonClass::addPolygon(QGeoCoordinate point1, QGeoCoordinate point2, QGeoCoordinate point3, QGeoCoordinate point4 , QGeoCoordinate point5)
{

    QJsonObject feature ;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"]="Feature";
    feature["properties"] = properties ;
    geometry["type"] = "Polygon" ;

    coordinates.append(QJsonArray({point1.latitude(),point1.longitude()}));
    coordinates.append(QJsonArray({point2.latitude(),point2.longitude()}));
    coordinates.append(QJsonArray({point3.latitude(),point3.longitude()}));
    coordinates.append(QJsonArray({point4.latitude(),point4.longitude()}));
    coordinates.append(QJsonArray({point5.latitude(),point5.longitude()}));
    coordinates.append(QJsonArray({point1.latitude(),point1.longitude()})); // closing the polygon by adding the first point again

    geometry["coordinates"]=QJsonArray({coordinates});
    feature["geometry"] = geometry ;

    features_.append(feature) ;


}

void GeojsonClass::addCircle(const QGeoCoordinate &center, double radius)
{

    QJsonObject feature ;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"] = "Feature";
    feature["properties"] = properties ;
    geometry["type"] = "Polygon" ;

    for(int i = 0 ; i <360 ; i+= 10){

        QGeoCoordinate point = center.atDistanceAndAzimuth(radius,i) ;
        coordinates.append(QJsonArray{point.longitude(),point.latitude()}) ;


    }

    //close the circle by adding the first point again

    coordinates.append(coordinates.at(0)) ;

    geometry["coordinates"] = QJsonArray({coordinates});
    feature["geometry"] = geometry ;

    features_.append(feature) ;



}


void GeojsonClass::writeToFile()
{
    QFile geoJsonFile(filename_);
    if(!geoJsonFile.open(QIODevice::WriteOnly|QIODevice::Text)){

        qWarning()<<"Faild to open file for writing";
        return ;

    }
    geojson_["features"]= features_;
    QJsonDocument jsonDoc(geojson_);
    geoJsonFile.write(jsonDoc.toJson());
    geoJsonFile.close();

    qDebug()<<"GeoJson file create suuccessfully : " << filename_ ;
}
