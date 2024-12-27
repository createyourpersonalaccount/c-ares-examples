((c-mode
  . ((eval
      . (keymap-set
         c-mode-map
         "C-c m"
         (lambda ()
           (interactive)
           (let ((project-root
                  (locate-dominating-file default-directory ".git")))
             (compile
              (format "cmake -E chdir %s cmake --workflow --preset custom"
                      project-root)))))))))
