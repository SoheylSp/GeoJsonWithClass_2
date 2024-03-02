#include <iostream>
#include <geojsonclass.h>
int main()
{
    GeojsonClass geoJson("lat_lon_ines.geojson");

    for (int lat = -360 ; lat <= 360 ; lat +=2 ){
        for (int lon = -180 ; lon <= 180 ; lon++){

            geoJson.addLine(-lat,lon,lat,lon);
            geoJson.addLine(lat,lon,lat,-lon);



        }
    }

    geoJson.writeToFile();
    return 0 ;

}
