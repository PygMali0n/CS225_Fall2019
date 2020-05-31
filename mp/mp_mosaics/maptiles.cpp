/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
     int rows = theSource.getRows();
     int columns = theSource.getColumns();
     map<Point<3>, size_t> pairs;
     std::vector<Point<3>> points;
     for (size_t i = 0; i < theTiles.size(); i++) {
       LUVAPixel pixel = theTiles[i].getAverageColor();
       Point<3> point = convertToXYZ(pixel);
       points.push_back(point);
       pairs.insert(pair<Point<3>, size_t>(point, i));
     }
     MosaicCanvas* canvas = new MosaicCanvas(rows, columns);
     KDTree<3>* tree = new KDTree<3>(points);
     for (int i = 0; i<rows; i++) {
       for (int j = 0; j<columns; j++) {
         LUVAPixel region_color = theSource.getRegionColor(i, j);
         Point<3> region_point = convertToXYZ(region_color);
         Point<3> close_point = tree->findNearestNeighbor(region_point);
         canvas->setTile(i,j, &theTiles[pairs[close_point]]);
       }
     }

     return canvas;

}
