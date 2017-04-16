//g++ -o asd.exe Backtrack.cpp
// ./asd.exe

#include <iostream>
#include <vector>

using namespace std;

// bool MayQueAnterior(std::vector<int>& ent, int cant, std::vector<int>& sal){
// 	bool flag = true;
// 	int i = cant;
// 	while(i != 0 && flag){
// 		i--;
// 		if(sal[i] == 1){
// 			flag = false;
// 		}
// 	}
// 	if(flag || ent[i] < ent[cant]){
// 		return true;
// 	}else{
// 		return false;
// 	}
// }

// bool MenQueAnterior(std::vector<int>& ent, int cant, std::vector<int>& sal){
// 	bool flag = true;
// 	int i = cant;
// 	while(i != 0 && flag){
// 		i--;
// 		if(sal[i] == 2){
// 			flag = false;
// 		}
// 	}
// 	if(flag || ent[i] > ent[cant]){
// 		return true;
// 	}else{
// 		return false;
// 	}	
// }

// bool PintaRojo(std::vector<int>& ent, int cant, std::vector<int>& sal){
// 	if(MayQueAnterior(ent, cant, sal)){
// 		return true;
// 	}else{
// 		return false;
// 	}
// }

// bool PintaAzul(std::vector<int>& ent, int cant, std::vector<int>& sal){
// 	if(MenQueAnterior(ent, cant, sal)){
// 		return true;
// 	}else{
// 		return false;
// 	}
// }

// void mostrarVector(std::vector<int>& vec){
// 	cout << "[";
// 	for(int i = 0; i < vec.size() - 1; i++){
// 		cout << vec[i] << ", ";
// 	}
// 	cout << vec[vec.size() - 1] << "]" << endl;
// }

// int minDeVector(std::vector<int>& vec){
// 	int min = vec[0];
// 	for(int i = 1; i < vec.size(); i++){
// 		if(vec[i] < min){
// 			min = vec[i];
// 		}
// 	}
// 	return min;
// }

int Ej1Aux(std::vector<int>& ent, int n, int cant, int sinpintar, int &res, int ultAz, int ultRo, bool HayAzPint, bool HayRojPint){ 
	if(cant == n){		// llego a una hoja
		if(sinpintar < res){		// si la cantidad de sinpintar es menor que el mejor resultado que ya tengo, entonces lo actualizo
			res = sinpintar;
		}
		return res;
	}
	if(ent[cant] > ent[ultRo] || cant == 0 || (HayRojPint == 0)){	// si el número puede pintarse de rojo, entonces sigo por la rama que corresponde a pintar al elemento de rojo
		Ej1Aux(ent, n, cant + 1, sinpintar, res, ultAz, cant, HayAzPint, HayRojPint + 1);
	}
	if(ent[cant] < ent[ultAz] || cant == 0 || (HayAzPint == 0)){	// si el número puede pintarse de azul, entonces sigo por la rama que corresponde a pintar al elemento de azul
		Ej1Aux(ent, n, cant + 1, sinpintar, res, cant, ultRo, HayAzPint + 1, HayRojPint);
	}
	Ej1Aux(ent, n, cant+1, sinpintar + 1, res, ultAz, ultRo, HayAzPint, HayRojPint);
}

int Ej1(std::vector<int>& ent, int n){
	int res = ent.size();
	Ej1Aux(ent, n, 0, 0, res, 0, 0, 0, 0);
	return res;
}


// PRIMERO DE TODOS, MUCHA MEMORIA ADICIONAL


// void ColorearAux2(std::vector<int>& ent, int n, int cant, std::vector<int>& sal, std::vector<int>& res){  // optimizar 
// 	if(cant == n){
// 		int sincolorear = 0;
// 		for(int i = 0; i < sal.size(); i++){
// 			if(sal[i] == 3){
// 				sincolorear++;
// 			}
// 		}
// 		mostrarVector(sal);
// 		res.push_back(sincolorear);
// 		return;
// 	}
// 		if(PintaRojo(ent, cant, sal)){
// 			sal[cant] = 1;
// 			ColorearAux2(ent, n, cant+1, sal, res);
// 		}
// 		if(PintaAzul(ent, cant, sal)){
// 			sal[cant] = 2;
// 			ColorearAux2(ent, n, cant+1, sal, res);
// 		}
// 		sal[cant] = 3;
// 		ColorearAux2(ent, n, cant+1, sal,res);
// }

// int Colorear2(std::vector<int>& ent, int n){
// 	std::vector<int> vc(n);
// 	std::vector<int> result(0);
// 	cout << endl;
// 	ColorearAux2(ent, n, 0, vc, result);
// 	cout << minDeVector(result) << endl;
// 	return minDeVector(result);
// }


// SEGUNDO, CON UN VECTOR SALIDA SOLO PARA VER EL OUTPUT


// int ColorearAux(std::vector<int>& ent, int n, int cant, int sinpintar, int &res, int ultAz, int ultRo, bool HayAzPint, bool HayRojPint, std::vector<int>& sal){  // optimizar 
// 	if(cant == n){
// 		if(sinpintar < res){
// 			res = sinpintar;
// 		}
// 		// mostrarVector(sal);
// 		return res;
// 	}
// 	if(ent[cant] > ent[ultRo] || cant == 0 || (HayRojPint == 0)){
// 		sal[cant] = 1;
// 		ColorearAux(ent, n, cant + 1, sinpintar, res, ultAz, cant, HayAzPint, HayRojPint + 1, sal);
// 	}
// 	if(ent[cant] < ent[ultAz] || cant == 0 || (HayAzPint == 0)){
// 		sal[cant] = 2;	
// 		ColorearAux(ent, n, cant + 1, sinpintar, res, cant, ultRo, HayAzPint + 1, HayRojPint, sal);
// 	}
// 	sal[cant] = 3;
// 	ColorearAux(ent, n, cant+1, sinpintar + 1, res, ultAz, ultRo, HayAzPint, HayRojPint, sal);
// }

// int Colorear(std::vector<int>& ent, int n){
// 	std::vector<int> v(n);
// 	int res = ent.size();
// 	ColorearAux(ent, n, 0, 0, res, 0, 0, 0, 0, v);
// 	// cout << res << endl;
// 	// mostrarVector(result);
// 	return res;
// }



// recordar no asignar algo en el medio de la recursión porque cambia los valores en todos lados!!!!
// tenés que cambiar el parámetro cuando hacés el paso recursivo (o sea, cambiarlo como parámetro de la función)
// El mejor optimizado es Colorear y ColorearAux ya que no tienen vectores adicionales (mem adic). Dejo el vector sal para poder ver la salida
// time ./ejecutable