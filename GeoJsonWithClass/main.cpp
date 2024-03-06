#include <iostream>
#include <geojsonclass.h>
int main()
{
    GeojsonClass geoJson("lat_lon_ines.geojson");


    /* for (int lat = -360 ; lat <= 360 ; lat +=2 ){
        for (int lon = -180 ; lon <= 180 ; lon++){

            geoJson.addLine(-lat,lon,lat,lon);
            geoJson.addLine(lat,lon,lat,-lon);
            geoJson.addX1(lat,lon);
            geoJson.addX2(lat,lon);



        }
    }
    */




  /*  QGeoCoordinate c1 ;
    c1.setLatitude(100);
    c1.setLongitude(40);

    QGeoCoordinate c2 ;
    c2.setLatitude(120);
    c2.setLongitude(50);

    QGeoCoordinate c3 ;
    c3.setLatitude(130) ;
    c3.setLongitude(60);

    QGeoCoordinate c4 ;
    c4.setLatitude(125);
    c4.setLongitude(72);

    QGeoCoordinate c5 ;
    c5.setLatitude(140);
    c5.setLongitude(42);


    geoJson.addPolygon(c1,c2,c3,c4,c5);
*/

    QGeoCoordinate center ;
    center.setLatitude(-78);
    center.setLongitude(0) ;
       double radius = 800000;

       geoJson.addCircle(center,radius) ;



    geoJson.writeToFile();
    return 0 ;

}
