#include "model/fuzzy_driver.h"
#include <iostream>
#include  <algorithm>

FuzzyDriver::FuzzyDriver(CarGui* c) : car(c)
{
    this->fuzzySets = this->defineCarFuzzySets();
    this->angleSets = this->defineAnglesFuzzySets();
    this->outputSets = this->defineOutput();
    this->run();
}

//patricia
void FuzzyDriver::run()
{
    double x = 0, y = 0, angulo;
    QList<double> pesoAngulos;
    QList<double> pesoX;
    QList<double> saidas;
    FuzzySet auxiliar;
    QList<QList<double> > ativadoraRegrasSaidas;

    std::cout << "FuzzyDriver::run: Starting fuzzy driver !!!" << std::endl;

    //comeca aqui

    while (y >= 0 && y <= 600 && x >= 0 && x <= 800) {
        ativadoraRegrasSaidas = QList<QList<double> >();
        pesoX = QList<double>();
        pesoAngulos = QList<double>();
        saidas = QList<double>();

        std::cout << "FuzzyDriver::run: Comecando uma iteracao" << std::endl;

        x = car->getPos().x();
        y = car->getPos().y();

        if(!this->car) {
            //OPS...ERROR, lets prevent a core dump.
            std::cout << "FuzzyDriver::run: FATAL ERROR, Car is NULL, ABORTING !!!" << std::endl;
            return;
        }

        angulo = car->getRotation();

        std::cout << "FuzzyDriver::run: angulo do carro eh [" << angulo << "]" << std::endl;
        std::cout << "FuzzyDriver::run: inserindo peso dos angulos" << std::endl;

        for (int i = 0; i < nAngulos; i++) {
            pesoAngulos.insert(i, 0);
            pesoAngulos.insert(i, pesoAngulos.at(i) + this->angleSets[i].y(angulo));
            pesoAngulos.insert(i, pesoAngulos.at(i) + this->angleSets[i].y(angulo - 360));
            std::cout << "FuzzyDriver::run: angleSets[" << i << "].y(" << angulo << ") = " << this->angleSets[i].y(angulo) << std::endl;
            std::cout << "FuzzyDriver::run: angleSets[" << i << "].y(" << angulo - 360 << ") = " << this->angleSets[i].y(angulo - 360) << std::endl;
            std::cout << "FuzzyDriver::run: pesoAngulos[" << i << "] = " << pesoAngulos[i] << std::endl;
        }

        std::cout << "FuzzyDriver::run: preenchendo pesoX" << std::endl;
        for (int i = 0; i < nX; i++) {
            pesoX.insert(i, this->fuzzySets[i].y(x));
            std::cout << "FuzzyDriver::run: pesoX[" << i << "] = " << pesoX[i] << std::endl;
        }

        std::cout << "FuzzyDriver::run: construindo ativadoraRegrasSaidas" << std::endl;
        for (int i = 0; i < nAngulos; i++) {
            ativadoraRegrasSaidas.append(QList<double>());

            for (int j = 0; j < nX; j++) {
                ativadoraRegrasSaidas[i].append(std::min(pesoAngulos[i],pesoX[j]));
                std::cout << "FuzzyDriver::run: ativadoraRegrasSaidas [" << i << "] [" << j << "] = " << ativadoraRegrasSaidas[i][j] << std::endl;
            }
        }

        std::cout << "FuzzyDriver::run: definindo saidas" << std::endl;
        saidas.insert(0,ativadoraRegrasSaidas.at(4).at(4));
        saidas.insert(0,std::max(ativadoraRegrasSaidas.at(5).at(4), saidas.at(0)));
        saidas.insert(0,std::max(ativadoraRegrasSaidas.at(6).at(4), saidas.at(0)));
        saidas.insert(0,std::max(ativadoraRegrasSaidas.at(5).at(3), saidas.at(0)));
        saidas.insert(0,std::max(ativadoraRegrasSaidas.at(6).at(3), saidas.at(0)));

        saidas.insert(1,ativadoraRegrasSaidas.at(2).at(4));
        saidas.insert(1,std::max(ativadoraRegrasSaidas.at(3).at(4), saidas.at(1)));
        saidas.insert(1,std::max(ativadoraRegrasSaidas.at(3).at(3), saidas.at(1)));
        saidas.insert(1,std::max(ativadoraRegrasSaidas.at(4).at(3), saidas.at(1)));
        saidas.insert(1,std::max(ativadoraRegrasSaidas.at(5).at(2), saidas.at(1)));
        saidas.insert(1,std::max(ativadoraRegrasSaidas.at(6).at(2), saidas.at(1)));
        saidas.insert(1,std::max(ativadoraRegrasSaidas.at(6).at(1), saidas.at(1)));

        saidas.insert(2,ativadoraRegrasSaidas.at(1).at(4));
        saidas.insert(2,std::max(ativadoraRegrasSaidas.at(2).at(3), saidas.at(2)));
        saidas.insert(2,std::max(ativadoraRegrasSaidas.at(4).at(2), saidas.at(2)));
        saidas.insert(2,std::max(ativadoraRegrasSaidas.at(5).at(1), saidas.at(2)));
        saidas.insert(2,std::max(ativadoraRegrasSaidas.at(6).at(0), saidas.at(2)));

        saidas[3] = ativadoraRegrasSaidas.at(3).at(2);

        saidas.insert(4,ativadoraRegrasSaidas.at(0).at(4));
        saidas.insert(4,std::max(ativadoraRegrasSaidas.at(1).at(3), saidas.at(4)));
        saidas.insert(4,std::max(ativadoraRegrasSaidas.at(2).at(2), saidas.at(4)));
        saidas.insert(4,std::max(ativadoraRegrasSaidas.at(4).at(1), saidas.at(4)));
        saidas.insert(4,std::max(ativadoraRegrasSaidas.at(5).at(0), saidas.at(4)));

        saidas.insert(5,ativadoraRegrasSaidas.at(0).at(3));
        saidas.insert(5,std::max(ativadoraRegrasSaidas.at(0).at(2), saidas.at(5)));
        saidas.insert(5,std::max(ativadoraRegrasSaidas.at(1).at(2), saidas.at(5)));
        saidas.insert(5,std::max(ativadoraRegrasSaidas.at(2).at(1), saidas.at(5)));
        saidas.insert(5,std::max(ativadoraRegrasSaidas.at(3).at(1), saidas.at(5)));
        saidas.insert(5,std::max(ativadoraRegrasSaidas.at(3).at(0), saidas.at(5)));
        saidas.insert(5,std::max(ativadoraRegrasSaidas.at(4).at(0), saidas.at(5)));

        saidas.insert(6,ativadoraRegrasSaidas.at(0).at(1));
        saidas.insert(6,std::max(ativadoraRegrasSaidas.at(0).at(0), saidas.at(6)));
        saidas.insert(6,std::max(ativadoraRegrasSaidas.at(1).at(1), saidas.at(6)));
        saidas.insert(6,std::max(ativadoraRegrasSaidas.at(1).at(0), saidas.at(6)));
        saidas.insert(6,std::max(ativadoraRegrasSaidas.at(2).at(0), saidas.at(6)));

        std::cout << "FuzzyDriver::run: saidas definidas" << std::endl;

        auxiliar = FuzzySet();
        for (int i = 0; i < this->outputSets.size(); i++){
            std::cout << "saida [" << i << "] = " << saidas.at(i) << std::endl;
            if (saidas.at(i) > 0) {
                if (auxiliar.size() > 0){
                    auxiliar = auxiliar.ou(this->outputSets[i].cepar(saidas.at(i)));
                }else{
                    auxiliar = this->outputSets[i].cepar(saidas.at(i));
                }
            }
        }

        if (auxiliar.size() == 0) {
                std::cout << "Breaked" << std::endl;
                break;
        }
        double maneuver  = auxiliar.centroide();
        std::cout << "FuzzyDriver::run: maneuver[" <<  maneuver << "]" << std::endl;
        car->stepManeuver(maneuver);
    }
}



QList<FuzzySet> FuzzyDriver::defineAnglesFuzzySets()
{
    //angulos
    FuzzySet RB, RU, RV, VE, LV, LU, LB;
    RB = FuzzySet();
    RB = FuzzySet();
    RU = FuzzySet();
    RV = FuzzySet();
    VE = FuzzySet();
    LV = FuzzySet();
    LU = FuzzySet();
    LB = FuzzySet();

    RB.add(QPoint(-100, 0));
    RB.add(QPoint(-45, 1));
    RB.add(QPoint(10, 0));

    RU.add(QPoint(-10, 0));
    RU.add(QPoint(35, 1));
    RU.add(QPoint(60, 0));

    RV.add(QPoint(45, 0));
    RV.add(QPoint(67.5, 1));
    RV.add(QPoint(90, 0));

    VE.add(QPoint(80, 0));
    VE.add(QPoint(90, 1));
    VE.add(QPoint(100, 0));

    LV.add(QPoint(90, 0));
    LV.add(QPoint(112.5, 1));
    LV.add(QPoint(135, 0));

    LU.add(QPoint(120, 0));
    LU.add(QPoint(155, 1));
    LU.add(QPoint(190, 0));

    LB.add(QPoint(170, 0));
    LB.add(QPoint(225, 1));
    LB.add(QPoint(280, 0));

    QList<FuzzySet> angleSets;

    angleSets.append(RB);
    angleSets.append(RU);
    angleSets.append(RV);
    angleSets.append(VE);
    angleSets.append(LV);
    angleSets.append(LU);
    angleSets.append(LB);

    return angleSets;
}

QList<FuzzySet> FuzzyDriver::defineCarFuzzySets()
{
    FuzzySet LE, LC, CE, RC, RI;
    LE = FuzzySet();
    LC = FuzzySet();
    CE = FuzzySet();
    RC = FuzzySet();
    RI = FuzzySet();

    LE.add(QPoint(0, 1));
    LE.add(QPoint(80, 1));
    LE.add(QPoint(255, 0));

    LC.add(QPoint(240, 0));
    LC.add(QPoint(320, 1));
    LC.add(QPoint(400, 0));

    CE.add(QPoint(360, 0));
    CE.add(QPoint(400, 1));
    CE.add(QPoint(440, 0));

    RC.add(QPoint(400, 0));
    RC.add(QPoint(480, 1));
    RC.add(QPoint(560, 0));

    RI.add(QPoint(520, 0));
    RI.add(QPoint(720, 1));
    RI.add(QPoint(800, 1));

    QList<FuzzySet> carFuzzySets;
    carFuzzySets.append(LE);
    carFuzzySets.append(LC);
    carFuzzySets.append(CE);
    carFuzzySets.append(RC);
    carFuzzySets.append(RI);
    return carFuzzySets;

}

QList<FuzzySet> FuzzyDriver::defineOutput()
{
    FuzzySet NB, NM, NS, ZE, PS, PM, PB;
    NB = FuzzySet();
    NM = FuzzySet();
    NS = FuzzySet();
    ZE = FuzzySet();
    PS = FuzzySet();
    PM = FuzzySet();
    PB = FuzzySet();

    NB.add(QPoint(-1, 1));
    NB.add(QPoint(-0.5, 0));

    NM.add(QPoint(-1, 0));
    NM.add(QPoint(-0.5, 1));
    NM.add(QPoint(-0.3, 0));

    NS.add(QPoint(-0.5, 0));
    NS.add(QPoint(-0.3, 1));
    NS.add(QPoint(0, 0));

    ZE.add(QPoint(-0.3, 0));
    ZE.add(QPoint(0, 1));
    ZE.add(QPoint(0.3, 0));

    PS.add(QPoint(0, 0));
    PS.add(QPoint(0.3, 1));
    PS.add(QPoint(0.5, 0));

    PM.add(QPoint(0.3, 0));
    PM.add(QPoint(0.5, 1));
    PM.add(QPoint(1, 0));

    PB.add(QPoint(0.5, 0));
    PB.add(QPoint(1, 1));

    QList<FuzzySet> outputSets;
    outputSets.append(NB);
    outputSets.append(NM);
    outputSets.append(NS);
    outputSets.append(ZE);
    outputSets.append(PS);
    outputSets.append(PM);
    outputSets.append(PB);

    return outputSets;
}


