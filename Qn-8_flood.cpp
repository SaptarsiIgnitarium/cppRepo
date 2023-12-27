#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);
void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor);

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 0, sc = 2, newColor = 5;

    cout << "Original Image : "<<endl;

    for (const auto& row : image)
    {
        for(int pixel : row)
        {
            cout << pixel <<" ";
        }
        cout << endl;
    }
    
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Modified Image : "<<endl;

    for (const auto& row : result)
    {
        for(int pixel : row)
        {
            cout << pixel <<" ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    if (image[sr][sc] == newColor) //new color is same as original color
    {
        return image;
    }

    int originalColor = image[sr][sc];
    dfs(image, sr, sc, newColor, originalColor);

    return image;
}

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor)
{
    //boundary condition
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != originalColor)
    {
        return;
    }

    image[sr][sc] = newColor;

    dfs(image, sr+1, sc, newColor, originalColor);
    dfs(image, sr-1, sc, newColor, originalColor);
    dfs(image, sr, sc+1, newColor, originalColor);
    dfs(image, sr, sc-1, newColor, originalColor);

    //for down up right left of pixel
}