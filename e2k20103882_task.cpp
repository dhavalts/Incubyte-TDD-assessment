#include <iostream>
using namespace std;

class GalacticSpacecraft {
private:
    int x, y, z;
    char direction;

public:
    GalacticSpacecraft(int startX, int startY, int startZ, char startDirection)
        : x(startX), y(startY), z(startZ), direction(startDirection) {}

    void moveForward() {
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }
    }

    void moveBackward() {
        switch (direction) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x--;
                break;
            case 'W':
                x++;
                break;
        }
    }

    void turnLeft() {
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
        }
    }

    void turnRight() {
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
        }
    }

    void turnUp() {
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            direction = 'U';
            z++;
        }
    }

    void turnDown() {
        if (direction == 'N' || direction == 'S' || direction == 'E' || direction == 'W') {
            direction = 'D';
            z--;
        }
    }

    void printPosition() {
        cout << "Current Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Current Direction: " << direction << endl;
    }
};

int main() {
    int startX = 0, startY = 0, startZ = 0;
    char startDirection;

    cout << "Enter starting direction (N, S, E, W, U, D): ";
    cin >> startDirection;

    GalacticSpacecraft spacecraft(startX, startY, startZ, startDirection);

    char choice;
    do {
        cout << "Choose an action: (f)orward, (b)ackward, (l)eft, (r)ight, (u)p, (d)own, (q)uit: ";
        cin >> choice;

        switch (choice) {
            case 'f':
                spacecraft.moveForward();
                break;
            case 'b':
                spacecraft.moveBackward();
                break;
            case 'l':
                spacecraft.turnLeft();
                break;
            case 'r':
                spacecraft.turnRight();
                break;
            case 'u':
                spacecraft.turnUp();
                break;
            case 'd':
                spacecraft.turnDown();
                break;
            case 'q':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        spacecraft.printPosition();

    } while (choice != 'q');

    return 0;
}
