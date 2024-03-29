/*
 * Copyright © 2014 Intel Corporation
 *   Daniel Vetter <daniel.vetter@ffwll.ch>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#define DRM_IF_MAJOR 1
#define DRM_IF_MINOR 4

/* drm_irq.c */
extern unsigned int drm_timestamp_monotonic;

/* drm_fops.c */
extern struct mutex drm_global_mutex;
void drm_lastclose(struct drm_device *dev);

/* drm_pci.c */
int drm_irq_by_busid(struct drm_device *dev, void *data,
		     struct drm_file *file_priv);

/* drm_prime.c */
int drm_prime_handle_to_fd_ioctl(struct drm_device *dev, void *data,
				 struct drm_file *file_priv);
int drm_prime_fd_to_handle_ioctl(struct drm_device *dev, void *data,
				 struct drm_file *file_priv);

void drm_prime_init_file_private(struct drm_prime_file_private *prime_fpriv);
void drm_prime_destroy_file_private(struct drm_prime_file_private *prime_fpriv);
void drm_prime_remove_buf_handle_locked(struct drm_prime_file_private *prime_fpriv,
					struct dma_buf *dma_buf);

/* drm_info.c */
int drm_name_info(struct seq_file *m, void *data);
int drm_clients_info(struct seq_file *m, void* data);
int drm_gem_name_info(struct seq_file *m, void *data);

/* drm_irq.c */
int drm_control(struct drm_device *dev, void *data,
		struct drm_file *file_priv);
int drm_modeset_ctl(struct drm_device *dev, void *data,
		    struct drm_file *file_priv);

/* drm_auth.c */
int drm_getmagic(struct drm_device *dev, void *data,
		 struct drm_file *file_priv);
int drm_authmagic(struct drm_device *dev, void *data,
		  struct drm_file *file_priv);
int drm_setmaster_ioctl(struct drm_device *dev, void *data,
			struct drm_file *file_priv);
int drm_dropmaster_ioctl(struct drm_device *dev, void *data,
			 struct drm_file *file_priv);
int drm_master_open(struct drm_file *file_priv);
void drm_master_release(struct drm_file *file_priv);

/* drm_sysfs.c */
extern struct class *drm_class;

int drm_sysfs_init(void);
void drm_sysfs_destroy(void);
struct device *drm_sysfs_minor_alloc(struct drm_minor *minor);
int drm_sysfs_connector_add(struct drm_connector *connector);
void drm_sysfs_connector_remove(struct drm_connector *connector);

/* drm_gem.c */
int drm_gem_init(struct drm_device *dev);
void drm_gem_destroy(struct drm_device *dev);
int drm_gem_handle_create_tail(struct drm_file *file_priv,
			       struct drm_gem_object *obj,
			       u32 *handlep);
int drm_gem_close_ioctl(struct drm_device *dev, void *data,
			struct drm_file *file_priv);
int drm_gem_flink_ioctl(struct drm_device *dev, void *data,
			struct drm_file *file_priv);
int drm_gem_open_ioctl(struct drm_device *dev, void *data,
		       struct drm_file *file_priv);
void drm_gem_open(struct drm_device *dev, struct drm_file *file_private);
void drm_gem_release(struct drm_device *dev, struct drm_file *file_private);

int dsi_display_set_acl_mode(struct drm_connector *connector, int level);
int dsi_display_get_acl_mode(struct drm_connector *connector);
int dsi_display_set_hbm_mode(struct drm_connector *connector, int level);
int dsi_display_get_hbm_mode(struct drm_connector *connector);
int dsi_display_set_aod_mode(struct drm_connector *connector, int level);
int dsi_display_get_aod_mode(struct drm_connector *connector);
int dsi_display_set_srgb_mode(struct drm_connector *connector, int level);
int dsi_display_get_srgb_mode(struct drm_connector *connector);
int dsi_display_set_dci_p3_mode(struct drm_connector *connector, int level);
int dsi_display_get_dci_p3_mode(struct drm_connector *connector);
int dsi_display_set_night_mode(struct drm_connector *connector, int level);
int dsi_display_get_night_mode(struct drm_connector *connector);
int dsi_display_set_oneplus_mode(struct drm_connector *connector, int level);
int dsi_display_get_oneplus_mode(struct drm_connector *connector);
int dsi_display_set_adaption_mode(struct drm_connector *connector, int level);
int dsi_display_get_adaption_mode(struct drm_connector *connector);
int dsi_display_get_serial_number(struct drm_connector *connector);
int dsi_display_get_serial_number_year(struct drm_connector *connector);
int dsi_display_get_serial_number_mon(struct drm_connector *connector);
int dsi_display_get_serial_number_day(struct drm_connector *connector);
int dsi_display_get_serial_number_hour(struct drm_connector *connector);
int dsi_display_get_serial_number_min(struct drm_connector *connector);
int dsi_display_panel_mismatch_check(struct drm_connector *connector);
int dsi_display_panel_mismatch(struct drm_connector *connector);
int dsi_display_set_aod_disable(struct drm_connector *connector, int disable);
int dsi_display_get_aod_disable(struct drm_connector *connector);

/* drm_debugfs.c */
#if defined(CONFIG_DEBUG_FS)
int drm_debugfs_init(struct drm_minor *minor, int minor_id,
		     struct dentry *root);
int drm_debugfs_cleanup(struct drm_minor *minor);
int drm_debugfs_connector_add(struct drm_connector *connector);
void drm_debugfs_connector_remove(struct drm_connector *connector);
#else
static inline int drm_debugfs_init(struct drm_minor *minor, int minor_id,
				   struct dentry *root)
{
	return 0;
}

static inline int drm_debugfs_cleanup(struct drm_minor *minor)
{
	return 0;
}

static inline int drm_debugfs_connector_add(struct drm_connector *connector)
{
	return 0;
}
static inline void drm_debugfs_connector_remove(struct drm_connector *connector)
{
}
#endif
