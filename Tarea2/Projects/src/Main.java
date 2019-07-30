public class Main {


    public static void main(String[] args) {

        //INSTANCIA DE LA LISTA l
        ListaBolsa l = new ListaBolsa();

        //INSERCIÓN DE VALORES A LA LISTA L
        l.insertar(10,5);
        l.insertar(50,10);
        l.insertar(80,20);
        l.insertar(100,50);


        //IMPRIMIR LA LISTA DE VALORES
        l.imprimir();

        System.out.println("\n\n");

        //VERIFICAR SI LA LISTA ESTA VACIA
        if (l.esVacia()){
            System.out.println("La lista esta vacia");
        }else{
            System.out.println("La lista no esta vacia");
        }

        //VERIFICAR CUANTOS ELEMENTOS TIENE LA LISTA
        System.out.println("La lista tiene " + l.cuantos() + " elementos");



    }


}


class NodoBolsa{

    public int x,y;
    public NodoBolsa siguiente;


    public NodoBolsa(){
        x = y = 0;
        siguiente = null;
    }

    public NodoBolsa(int x, int y){
        this.x = x;
        this.y = y;
        siguiente = null;
    }

    public NodoBolsa(int x, int y, NodoBolsa siguiente){
        this.x = x;
        this.y = y;
        this.siguiente = siguiente;
    }

}

class ListaBolsa{

    NodoBolsa cabeza;
    NodoBolsa cola;
    int cantidad;


    public ListaBolsa(){
        cabeza = null;
        cola = null;
        cantidad = 0;
    }

    public boolean esVacia(){
        if(cabeza == null){
            return true;
        }else{
            return false;
        }
    }

    public int cuantos(){
        return cantidad;
    }

    public void insertar(int x, int y){
        if(cabeza == null){ // SI LA CABEZA DE LA LISTA SE ENCUENTRA VACIA
            cabeza = cola =  new NodoBolsa(x,y);
            cantidad++;
        }else{ //SI LA LISTA CONTIENE ELEMENTOS
            NodoBolsa nuevoNodo = new NodoBolsa(x,y, cabeza);
            cola.siguiente = nuevoNodo;
            cola = nuevoNodo;
            cantidad++;
        }
    }

    public void imprimir(){
        NodoBolsa aux = cabeza;
        int cAux = cantidad;

        while(cAux != 0){
            System.out.print("----> [ " + aux.x + " , " + aux.y + " ] " );
            aux = aux.siguiente;
            cAux--;
        }

    }


}
