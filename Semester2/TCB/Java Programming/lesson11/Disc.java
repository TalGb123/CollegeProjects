public class Disc {
    private String name;
    private Song[] songs;

    public Disc(String name, Song[] songs) {
        this.name = name;
        this.songs = songs;
    }

    public boolean exist(String nSong, String pSong) {
        for (int i=0; i < songs.length; i++) {
            if (songs[i].Status().equals(pSong + "/" + nSong)) {
                return true;
            }
        }
        return false;
    }

    public static String LargeDiscName(Disc d1, Disc d2){
        return d1.songs.length > d2.songs.length ? d1.name : d2.name;
    }
}
