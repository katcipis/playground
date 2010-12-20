#include "network.h"

Network::Network() {
}

void Network::inicializa(int ne, int q, int ns, int neuHid, double lrr) {
	this->nHidden = neuHid;
	this->nInputs = ne;
	this->nOutputs = ns;
	this->trainSize = q;
	this->lr = lrr;
	this->hidden = Layer();
	this->output = Layer();
	this->hidden.inicializa(this->nInputs, neuHid, 1, &(this->output), NULL,
			this->lr);
	this->output.inicializa(neuHid, this->nOutputs, 2, NULL, &(this->hidden),
			this->lr);

	this->inputs = QList<QList<double> > ();
	this->outputs = QList<QList<double> > ();

	this->simul = QList<double> ();
	this->o = QList<double> ();
	this->w = QList<double> ();
}

void Network::set_inputs(QList<double> in) {
	for (int i = 0; i < this->nInputs; i++) {
		simul[i] = in[i];
	}
}

void Network::feedfoward(int index) {
	if (index >= 0)
		this->hidden.calculate_output(this->inputs[index]);
	else
		this->hidden.calculate_output(this->simul);
	this->output.calculate_output(this->hidden.o);
	for (int i = 0; i < this->nOutputs; i++) {
		this->o.insert(i, output.o[i]);
	}
}

double Network::train(int e, double ep) {
	double erro = 1;
	int epocas = 0;
	while (++epocas < e && erro > ep) {
		erro = 0;
		for (int c = 0; c < trainSize; c++) {
			this->output.setTarget(outputs[c]);
			this->feedfoward(c);
			this->output.calc_erro();
			this->hidden.calc_erro();
			this->output.update_weights();
			this->hidden.update_weights();
			for (int s = 0; s < this->nOutputs; s++)
				erro += (pow(this->output.e[s], 2)) / 2;
		}
	}
	return erro;
}

void Network::openInputFile(QString file) {
	int mi;
	QString linha;
	QFile arquivo(file);
	if (arquivo.open(QFile::WriteOnly | QFile::Truncate)) {
		nInputs = 0;
		while ((linha = arquivo.readLine()) != NULL) {
			trainSize = 0;
			mi = 0;
			for (int i = 0; i <= linha.length(); i++)
				if (i == linha.length())
					inputs[trainSize][nInputs] = linha.mid(mi).toDouble();
				else if ((linha[i] == ' ') || (linha[i] == '\0') || (linha[i]
						== '	')) {
					inputs[trainSize][nInputs] = linha .mid(mi, i).toDouble();
					mi = i + 1;
					trainSize++;
				}
			nInputs++;
		}
		arquivo.close();
	}
}

void Network::openOutputFile(QString file) {
	int mi, colunas;
	QString linha;
	QFile arquivo(file);
	if (arquivo.open(QFile::WriteOnly | QFile::Truncate)) {
		nOutputs = 0;
		while ((linha = arquivo.readLine()) != NULL) {
			colunas = 0;
			mi = 0;
			for (int i = 0; i <= linha.length(); i++)
				if (i == linha.length())
					outputs[colunas][nOutputs] = linha.mid(mi).toDouble();
				else if ((linha[i] == ' ') || (linha[i] == '\0') || (linha[i]
						== '	')) {
					outputs[colunas][nOutputs] = linha.mid(mi, i).toDouble();
					mi = i + 1;
					colunas++;
				}
			nOutputs++;
		}
		arquivo.close();
	}
}

void Network::loadWeights(QString file) {
	QFile arquivo(file);
	if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	}

	int mi, c;
	QString linha;
	linha = arquivo.readLine();
	c = 0;
	mi = 0;
	for (int i = 0; i <= linha.length(); i++)
		if (i == linha.length())
			w[c] = linha.mid(mi).toDouble();
		else if ((linha[i] == ' ') || (linha[i] == '\0') || (linha[i] == '	')) {
			w[c] = linha.mid(mi, i).toDouble();
			mi = i + 1;
			c++;
		}
	setPesos(w);
	arquivo.close();
}

void Network::saveWeights(QString file) {
	QFile arquivo(file);
	if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream writeData(&arquivo);

	this->acumulaPesos();
	QString out = "";
	for (int i = 0; i < nHidden * (nInputs + 1) + (nHidden + 1) * nOutputs - 1; i++)
		writeData << w[i] << "	";

	writeData << w[nHidden * (nInputs + 1) + (nHidden + 1) * nOutputs - 1];

	arquivo.close();
}

void Network::acumulaPesos() {
	for (int nh = 0; nh < this->nHidden; nh++)
		for (int in = 0; in <= this->nInputs; in++)
			w.insert(nh * (nInputs + 1) + in, this->hidden.w[nh][in]);
	int offs = this->nHidden * (this->nInputs + 1);
	for (int no = 0; no < this->nOutputs; no++)
		for (int nhi = 0; nhi <= this->nHidden; nhi++)
			w.insert(offs + no * (this->nHidden + 1) + nhi,
					this->output.w[no][nhi]);
}

void Network::setPesos(QList<double> p) {
	for (int nh = 0; nh < this->nHidden; nh++)
		for (int in = 0; in <= this->nInputs; in++) {
			QList<double> aux = this->hidden.w[nh];
			aux.insert(in, p[nh * (nInputs + 1) + in]);
		}
	int offs = this->nHidden * (this->nInputs + 1);
	for (int no = 0; no < this->nOutputs; no++)
		for (int nhi = 0; nhi <= this->nHidden; nhi++) {
			QList<double> aux = this->output.w[no];
			aux.insert(nhi, p[offs + no * (this->nHidden + 1) + nhi]);
		}
}

void Network::simular(QList<double> input) {
	this->simul = input;
	this->feedfoward(-1);
}

