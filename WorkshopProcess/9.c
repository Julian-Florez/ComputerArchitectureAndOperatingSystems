for(cont1= 0; cont1<n; cont1++){
    pid= getpid();
    for(cont2= 0; cont2< cont1+2; cont2++) {
        nuevo= fork();
        if(nuevo == 0)
            break;
    }
    npid= getpid();
    if(npid== pid)
        break;
}