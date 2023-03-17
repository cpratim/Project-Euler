# Author: Pratim Chowdhary

# Clone the repository
if [ -d "Project-Euler" ]; then
    echo "Directory exists"
    cd Project-Euler
    git pull
    cd ..
else
    echo "Directory does not exist"
    git clone https://github.com/cpratim/Project-Euler
fi

# Change directory
cd Project-Euler

# Build the program
cmake -S .
cmake --build .

# Clear the screen
clear

# Run the program
./Project-Euler

# Clear the screen
clear

# Remove the executable
make clean