/*
~ Author    : leetcode.com/tridib_2003/
~ Problem   : 733. Flood Fill
~ Link      : https://leetcode.com/problems/flood-fill/
*/

class Solution {
public:

    void floodFillUtil(int r, int c, vector<vector<int> >& image, int x, int y, int validColor, int newColor) {

        static int rPos[] = {-1, 1, 0, 0};
        static int cPos[] = {0, 0, -1, 1};

        image[x][y] = newColor;

        for (int k = 0; k < 4; ++k) {

            int adjX = x + rPos[k];
            int adjY = y + cPos[k];

            if ((adjX >= 0 && adjX < r) && (adjY >= 0 && adjY < c) && (image[adjX][adjY] == validColor))
                floodFillUtil(r, c, image, adjX, adjY, validColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int validColor = image[sr][sc];

        if (validColor != newColor) {

            int r = image.size();
            int c = image[0].size();

            floodFillUtil(r, c, image, sr, sc, validColor, newColor);
        }

        return image;
    }
};
