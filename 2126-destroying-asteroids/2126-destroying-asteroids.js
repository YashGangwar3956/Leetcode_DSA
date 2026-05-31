var asteroidsDestroyed = function(mass, asteroids) {
const reducer = (previousValue, currentValue) => previousValue + currentValue;

    console.log(mass)
    let pacman = asteroids.sort((a,b) => a-b).reduce((p,c) => p >= c ? p + c : p = -Infinity, mass)
    
    return pacman > -Infinity ? true : false
};