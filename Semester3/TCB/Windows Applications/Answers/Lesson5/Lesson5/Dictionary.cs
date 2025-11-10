using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson5
{
    internal class Dictionary
    {
        private Word[] words;

        public Dictionary()
        {
            words = new Word[1000];
        }

        public Word TranslateFromHebrew(string st)
        {
            foreach (Word w in words)
            {
                if (w != null && w.getHebrewWord() == st)
                {
                    return w;
                }
            }
            return null;
        }

        public Word TranslateFromEnglish(string st)
        {
            foreach (Word w in words)
            {
                if (w != null && w.getEnglishWord() == st)
                {
                    return w;
                }
            }
            return null;
        }

        public void AddWord(Word w)
        {
            for (int i = 0; i < words.Length; i++)
            {
                if (words[i] == null)
                {
                    words[i] = new Word(w);
                    return;
                }
            }
        }

        public string showDictionary()
        {
            string str = "";
            foreach (Word w in words)
            {
                if (w != null)
                {
                    str += w.ToString() + "\n";
                }
            }
            return str;
        }

        public void Clear()
        {
            words = new Word[1000];
        }
    }
}
