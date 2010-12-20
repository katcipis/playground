#include "neural_driver.h"

neural_driver::neural_driver(CarGui* c): car(c) {
	rede = Network();
	rede.inicializa(2, 37, 1, 7, 0.01);
	rede.loadWeights("pesos.txt");
}

void neural_driver::setTruckPosition(int x, int y , double angulo) {
	car->setPos(x, y);
	car->setRotation(angulo);
}

void neural_driver::run() {

	double x = 0, y = 0, angulo, teste;
	QList<double> input;
	input = QList<double>();
	while (y >= -100 && y <= 600) {

		x = car->getPos().x();
		y = car->getPos().y();
		angulo = car->getRotation();
		input.insert(0, (int(angulo) % 360) / 360);
		input.insert(1, x / 800);
		rede.simular(input);
		teste = rede.o[0];
		teste = teste * 2 - 1;
		car->stepManeuver(teste);
		std::cout << teste << "	" << std::endl;
		std::cout << int(car->getRotation()) % 360 << "	"<< std::endl;
		std::cout << car->getPos().x() << "	"<< std::endl;
	}
}
